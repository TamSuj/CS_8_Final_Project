//
// Created by Tammy S on 11/5/23.
//

#include "Label.h"

Label::Label(std::string message) : Label(message, {0,0}){

}

Label::Label(std::string message, sf::Vector2f pos, int size) {
    text.setString(message);
    text.setPosition(pos);
    text.setCharacterSize(size);
    text.setFont(Font::getFont(OPEN_SANS));
    text.setFillColor(DEFAULT_TEXT_COLOR);
}

void Label::setString(const std::string &string) {
    text.setString(string);
}

void Label::setPosition(const sf::Vector2f &pos) {
    text.setPosition(pos);
}

void Label::setColor(const sf::Color color) {
    text.setFillColor(color);
}

void Label::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}

void Label::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Label::update() {

}

Snapshot &Label::getSnapshot() {

}

void Label::applySnapshot(const Snapshot &snapshot) {

}