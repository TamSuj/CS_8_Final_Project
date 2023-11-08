//
// Created by Tammy S on 11/2/23.
//

#ifndef SFML_TEMPLATE_CURSOR_H
#define SFML_TEMPLATE_CURSOR_H

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Letter.h"
#include "States.h"

class Cursor : public sf::Drawable, public States {
public:
    Cursor(sf::Time delay, sf::Color color = DEFAULT_TEXT_COLOR,  unsigned size=DEFAULT_TEXT_SIZE, char ch = '|');

    void setPosition(const sf::Vector2f & pos);
    sf::Vector2f getPosition();
    void setColor(sf::Color color);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;


private:
    sf::Clock clock;
    const sf::Time delay;
    bool show;
    Letter cursor;
};

#endif //SFML_TEMPLATE_CURSOR_H
