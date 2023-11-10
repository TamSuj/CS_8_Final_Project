//
// Created by Tammy S on 10/31/23.
//

#include "Box.h"

Box::Box() : Box(BOX_DEFAULT_SIZE){

}

Box::Box(const sf::Vector2f &size) : Box("", size){

}

Box::Box(const std::string &message, const sf::Vector2f &size) {
    box.setSize(size);
    setText(message);
}

void Box::setText(const std::string &message) {
    text.setString(message);
    Helper<sf::RectangleShape>::centerText(box, text.getTextObj());
}

void Box::setSize(sf::Vector2f size) {
    box.setSize(size);
}

void Box::setFillColor(sf::Color color) {
    box.setFillColor(color);
}

void Box::setOutlineColor(sf::Color color) {
    box.setOutlineColor(color);
}

void Box::setOutlineThickness(const int &thickness) {
    box.setOutlineThickness(thickness);
}

void Box::setPosition(const sf::Vector2f &pos) {
    box.setPosition(pos);
    text.setPosition(pos);
}

void Box::eventHandler(sf::RenderWindow &window, sf::Event event) {
//    If mouse is in the bound of the box
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(box.getGlobalBounds().contains(mpos))
        enableState(HOVERED);
    else
        disableState(HOVERED);

}

void Box::update() {
    if(checkState(HOVERED))
        box.setFillColor(LIGHT_BLUE); //Light blue
    else
        box.setFillColor(DARK_BLUE); //Dark blue
}

void Box::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    if(!checkState(HIDDEN))
        window.draw(box);

    window.draw(text);

}

Snapshot &Box::getSnapshot() {
    Snapshot snapshot("Box");
    return snapshot;
}

void Box::applySnapshot(const Snapshot &snapshot) {

}

sf::Vector2f Box::getPosition() const {
    return box.getPosition();
}

sf::Vector2f Box::getSize() const {
    return box.getSize();
}

Label Box::getText() const {
    return text;
}
