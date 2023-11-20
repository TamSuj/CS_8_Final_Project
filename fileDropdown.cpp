//
// Created by Tammy S on 11/18/23.
//

#include "fileDropdown.h"

fileDropdown::fileDropdown(FileTree<std::string> &tree, sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
    this->tree = &tree;

    setPosition(pos);
    setSize(size);

//    for(auto x : tree) {
//        lists.push_back(x);
//    }

//  Init header (box)
//    if(tree != nullptr)
//        box.setText(message.front());
    box.setPosition(pos);
    box.setSize(size);
    box.setTextPosition({pos.x + MARGIN_LEFT, pos.y + MARGIN_TOP});
    box.setFillColor(color);

//    init drop down menus
    for(int i = 1; i < lists.size(); ++i) {
        auto text = lists[i];
        Box* temp = new Box(text, {size.x, size.y});
        temp->setPosition({pos.x, pos.y + size.y * i});
        temp->setTextPosition({pos.x + MARGIN_LEFT, temp->getPosition().y + MARGIN_TOP});
        dropdowns.push_back(temp);
    }

    if (!img.loadFromFile("Materials/icon.png")) {
        // Handle the case where the image loading fails
        std::cout << "Image not found" << std::endl;
    }


    // Create a sprite and set its texture
    sprite.setTexture(img);
    sprite.setScale(0.08, 0.08);
    sprite.setPosition(pos.x + size.x - 30, pos.y + 10);


}

void fileDropdown::setPosition(sf::Vector2f pos) {
    position = pos;
    box.setPosition(pos);
    box.setTextPosition({pos.x + MARGIN_LEFT, pos.y + MARGIN_TOP});

    for(int i = 0; i < dropdowns.size(); ++i) {
        dropdowns[i]->setPosition({pos.x, pos.y + size.y * (i+1)});
        dropdowns[i]->setTextPosition({pos.x + MARGIN_LEFT, dropdowns[i]->getPosition().y + MARGIN_TOP});
    }
}

void fileDropdown::setSize(sf::Vector2f size) {
    this->size = size;
}

void fileDropdown::setHeader(const std::string &message) {
    box.setText(message);
}

void fileDropdown::setColor(sf::Color color) {
    box.setFillColor(color);
}

void fileDropdown::setHighlightColor(sf::Color color) {
    highlightColor = color;
}

sf::Vector2f fileDropdown::getPosition() {
    return position;
}

sf::Vector2f fileDropdown::getSize() {
    return size;
}

void fileDropdown::eventHandler(sf::RenderWindow &window, sf::Event event) {

    //If mouse is in the bound of the box, enable hovered state
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    if(mpos.x > box.getPosition().x && mpos.x < box.getPosition().x + box.getSize().x && mpos.y > box.getPosition().y && mpos.y < box.getPosition().y + box.getSize().y) {

        enableState(HOVERED);
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            toggleState(CLICKED);
        }

    }
    else {
        disableState(HOVERED);
    }

    if(checkState(CLICKED)) {
        for(auto i : dropdowns) {
            if(mpos.x > i->getPosition().x && mpos.x < i->getPosition().x + i->getSize().x && mpos.y > i->getPosition().y && mpos.y < i->getPosition().y + i->getSize().y){
                std::string selectedText = i->getTextString();
                i->setFillColor(highlightColor);

                if(event.type == sf::Event::MouseButtonPressed) {
//                    Send the header text to history stack before making changes
//                    History::push(getSnapshot(), this);

                    toggleState(CLICKED);
                }

            }else
                i->setFillColor(sf::Color::White);

        }
    }



//    If mpos isout of the area of the fileDropdown (header + dropdown area), disable clicked state
//    if(!(box.getGlobalBounds().contains(mpos) || dropdowns.back()->getGlobalBounds().contains(mpos)))
//        disableState(CLICKED);
}

void fileDropdown::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(checkState(CLICKED)) {
        for (auto x: dropdowns) {
            window.draw(sprite);
            window.draw(*x);
        }
    }

    window.draw(box);
}

void fileDropdown::update() {
//    if(checkState(HOVERED)) {
//        box.setOutlineThickness(3);
//        box.setOutlineColor(sf::Color::White);
//    }
//    else {
//        box.setOutlineThickness(0);
//    }

    //Center text
}

Snapshot fileDropdown::getSnapshot() {
    Snapshot snapshot(box.getText().getString());
    return snapshot;
}

void fileDropdown::applySnapshot(const Snapshot &snapshot) {
//    std::cout << "applying " << snapshot.getString() << std::endl;
    setHeader(snapshot.getString());
}