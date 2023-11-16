//
// Created by Tammy S on 11/14/23.
//

#include "MenuBar.h"

MenuBar::MenuBar(const std::string &text, sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
    std::vector<std::string> temp;
    temp.push_back(text);

    MenuBar(temp, pos, size, color);
}

MenuBar::MenuBar(const std::vector<std::string> message, sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
    for(auto x : message)
        lists.push_back(x);

    setPosition(pos);
    setSize(size);

//  Init header (box)
    if(!lists.empty())
        box.setText(message.front());
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

}

void MenuBar::setPosition(sf::Vector2f pos) {
    position = pos;
    box.setPosition(pos);
    box.setTextPosition({pos.x + MARGIN_LEFT, pos.y + MARGIN_TOP});

    for(int i = 0; i < dropdowns.size(); ++i) {
        dropdowns[i]->setPosition({pos.x, pos.y + size.y * (i+1)});
        dropdowns[i]->setTextPosition({pos.x + MARGIN_LEFT, dropdowns[i]->getPosition().y + MARGIN_TOP});
    }
}

void MenuBar::setSize(sf::Vector2f size) {
    this->size = size;
}

void MenuBar::setHeader(const std::string &message) {
    box.setText(message);
}

void MenuBar::setColor(sf::Color color) {
    box.setFillColor(color);
}

void MenuBar::setHighlightColor(sf::Color color) {
    highlightColor = color;
}

sf::Vector2f MenuBar::getPosition() {
    return position;
}

sf::Vector2f MenuBar::getSize() {
    return size;
}

void MenuBar::eventHandler(sf::RenderWindow &window, sf::Event event) {

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

//                if(event.type == sf::Event::MouseButtonPressed && changeWhenClicked) {
////                    Send the header text to history stack before making changes
//                    History::push(getSnapshot(), this);
//
//                    setHeader(selectedText);
//                    toggleState(CLICKED);
//                }

                if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    toggleState(CLICKED);
                }
            }else
                i->setFillColor(sf::Color::White);

        }
    }



//    If mpos isout of the area of the MenuBar (header + dropdown area), disable clicked state
//    if(!(box.getGlobalBounds().contains(mpos) || dropdowns.back()->getGlobalBounds().contains(mpos)))
//        disableState(CLICKED);
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(checkState(CLICKED)) {
        for (auto x: dropdowns) {
            window.draw(*x);
        }
    }

    window.draw(box);
}

void MenuBar::update() {
//    if(checkState(HOVERED)) {
//        box.setOutlineThickness(3);
//        box.setOutlineColor(sf::Color::White);
//    }
//    else {
//        box.setOutlineThickness(0);
//    }

    //Center text
}

Snapshot MenuBar::getSnapshot() {
    Snapshot snapshot(box.getText().getString());
    return snapshot;
}

void MenuBar::applySnapshot(const Snapshot &snapshot) {
//    std::cout << "applying " << snapshot.getString() << std::endl;
    setHeader(snapshot.getString());
}

