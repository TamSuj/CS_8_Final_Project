//
// Created by Tammy S on 11/9/23.
//

#include "DropdownList.h"

//dropdown.setSize({size.x, size.y * 2});
DropdownList::DropdownList() : DropdownList({"Header", "subset 1", "subset 2" , "subset 3"}, {100, 100}, {0, 0}) { }

DropdownList::DropdownList(const std::string &message) {
    lists.push_back(message);
}

DropdownList::DropdownList(const std::vector<std::string> &messageVec, sf::Vector2f pos, sf::Vector2f size) {
    for (auto w = messageVec.begin(); w != messageVec.end(); ++w)
        lists.push_back(*w);

    setPosition(pos);
    header.setPosition(pos);
    header.setSize(size);
    header.setFillColor(LIGHT_BLUE);
}

void DropdownList::setPosition(sf::Vector2f pos) {
    position = pos;
    header.setPosition(pos);
}

void DropdownList::push(const std::string& text){
    lists.push_back(text);

}

void DropdownList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(header);
    Box head(lists.front(), {position.x, position.y});
    head.setPosition({position.x + MARGIN_LEFT , position.y + MARGIN_TOP});
    head.setFillColor(sf::Color::Transparent);

    window.draw(head);

    if (checkState(CLICKED)){
        Box bg({header.getSize().x, header.getPosition().y + lineHeight * (lists.size()-1)});
        bg.setPosition({position.x, header.getPosition().y + lineHeight + 2});

        if(bg.getSize().y > lists.size() * lineHeight)
            bg.setSize({bg.getSize().x, static_cast<float>((lists.size()-1) * (lineHeight) + MARGIN_TOP)});

        window.draw(bg);

        for (auto w = lists.begin(); w != lists.end(); ++w) {
            Box dropdown(*w, {position.x, position.y + lineHeight * (w - lists.begin())});
            dropdown.setPosition(
                    {position.x + MARGIN_LEFT, position.y + lineHeight * (w - lists.begin()) + MARGIN_TOP});
            dropdown.setFillColor(sf::Color::Transparent);

            window.draw(dropdown);

//            if (w != lists.begin()) {
//                auto linePosY = dropdown.getPosition().y - lineHeight;
//                sf::Vertex lines[2];
//                lines[0] = sf::Vertex(sf::Vector2f(header.getPosition().x, linePosY), sf::Color(191, 191, 191));
//                lines[1] = sf::Vertex(sf::Vector2f(header.getSize().x, linePosY),
//                                      sf::Color(191, 191, 191)); // Additional vertex if needed
//
//                window.draw(lines, 2, sf::LineStrip); // Draw the vertex array}
//
//            }
        }
    }

}

void DropdownList::clear() {
    textList.clear();
}

void DropdownList::eventHandler(sf::RenderWindow &window, sf::Event event) {
    History::addEventHandler(window, event);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        // Get the mouse position in window coordinates
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if(header.getPosition().x <= mousePos.x && mousePos.x <= header.getPosition().x + header.getSize().x &&
                header.getPosition().y <= mousePos.y && mousePos.y <= header.getPosition().y + header.getSize().y)
            toggleState(CLICKED);



        //    Check if user click on the menu (options)
        if(checkState(CLICKED)){
            if(header.getPosition().x <= mousePos.x && mousePos.x <= header.getPosition().x + header.getSize().x && mousePos.y >= header.getPosition().y){
//                std::cout << "mousePos: " << mousePos.y << " vs header.pos.y: " << header.getPosition().y << std::endl;
                int index = (mousePos.y - header.getPosition().y) / lineHeight;
                std::string word = lists[index];


                if(changeWhenClicked && index != 0) {
                    lists.front() = word;
                    toggleState(CLICKED);
                }
            }

        }
    }

}

void DropdownList::update() {
//    header.setText(lists.front());
    header.getText().setPosition({header.getText().getPosition().x + MARGIN_LEFT, header.getText().getPosition().y + MARGIN_TOP});
//    Helper<Box>::centerText(header, header.getText().getTextObj());

    menuArea = {header.getSize().x, header.getPosition().y + lineHeight * (lists.size()-1)};
}

Snapshot &DropdownList::getSnapshot() {
    std::string text = "";
    for (auto w = textList.begin(); w != textList.end(); ++w)
        text += w->getString();

    Snapshot snapshot(text);
    return snapshot;
}

void DropdownList::applySnapshot(const Snapshot &snapshot) {

//    Clear the text to replace with a new one
    clear();
    push(snapshot.getString());
}

sf::Vector2f DropdownList::getPosition() {
    return header.getPosition();
}

sf::Vector2f DropdownList::getPosition() const{
    return getPosition();
}

bool DropdownList::empty() {
    return lists.empty();
}

void DropdownList::setLineHeight(const int height) {
    lineHeight = height;
}

void DropdownList::setHeader(const std::string &message) {
    lists.front() = message;
}

sf::Vector2f DropdownList::getSize() {
    return header.getSize();
}

void DropdownList::setColor(sf::Color color) {
    header.setFillColor(color);
}

void DropdownList::disableChangeWhenClicked() {
    changeWhenClicked = false;
}
