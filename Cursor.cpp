//
// Created by Tammy S on 11/2/23.
//

#include "Cursor.h"

Cursor::Cursor(sf::Time delay, sf::Color color, unsigned int size, char ch)
: delay(delay), show(true)
{
    enableState(HIDDEN);
    cursor = Letter(ch);
    cursor.setFillColor(color);
    cursor.setCharacterSize(size);
}

void Cursor::setPosition(const sf::Vector2f &pos)
{
    cursor.setPosition(pos);
}

sf::Vector2f Cursor::getPosition() {
    return cursor.getPosition();
}

void Cursor::setColor(sf::Color color) {
    cursor.setFillColor(color);
}

void Cursor::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    if(!checkState(HIDDEN))
        target.draw(cursor, state);
}

void Cursor::update() {
//    if (clock.getElapsedTime() > delay) {
//        show = !show;
//        clock.restart();
//    }
    if (clock.getElapsedTime() > delay) {
        toggleState(HIDDEN);
        clock.restart();
    }

}
