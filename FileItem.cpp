//
// Created by Tammy S on 11/19/23.
//

#include "FileItem.h"

FileItem::FileItem() {

}

FileItem::FileItem(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position) {

    

}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    Box::draw(window, states);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

sf::FloatRect FileItem::getGlobalBounds() const {
    return Sprite::getGlobalBounds();
}

sf::Vector2f FileItem::getSize() const {
    return Box::getSize();
}

sf::Vector2f FileItem::getPosition() const {
    return Box::getPosition();
}

void FileItem::setPosition(sf::Vector2f pos) {

}

void FileItem::setIcon(Image::image icon) {

}
