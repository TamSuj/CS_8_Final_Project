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

std::string Label::getString() {
    return text.getString();
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

int Label::getFontSize() {
    return text.getCharacterSize();
}

void Label::eventHandler(sf::RenderWindow &window, sf::Event event) {

    if(KeyboardShortcut::isZoomIn())
        text.setCharacterSize(getFontSize() + 2);
    else if(KeyboardShortcut::isZoomOut())
        text.setCharacterSize(getFontSize() - 2);
}

void Label::update() {

}

Snapshot Label::getSnapshot() {

}

void Label::applySnapshot(const Snapshot &snapshot) {

}

const sf::Text Label::getTextObj() {
    return text;
}

void Label::setFontSize(const int size) {
    text.setCharacterSize(size);
}
