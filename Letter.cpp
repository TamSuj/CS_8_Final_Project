//
// Created by Tammy S on 10/18/23.
//

#include "Letter.h"

Letter::Letter() : Letter('\0'){ }

Letter::Letter(char letter) : sf::Text() {
    setFont(Font::getFont(OPEN_SANS));
    setString(std::string(1, letter));
    setCharacterSize(DEFAULT_TEXT_SIZE);
    setFillColor(DEFAULT_TEXT_COLOR);
}
