//
// Created by Tammy S on 11/5/23.
//

#ifndef SFML_TEMPLATE_LABEL_H
#define SFML_TEMPLATE_LABEL_H


#include "GUIComponent.h"
#include "Constants.h"
#include "Font.h"

class Label : public GUIComponent{
    sf:: Text text;
public:
    Label(std::string message);
    Label(std::string message = "", sf::Vector2f pos = {0,0}, int size = DEFAULT_TEXT_SIZE);
    void setString(const std::string& string);
    void setPosition(const sf::Vector2f& pos);
    void setColor(const sf::Color color);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(); //Call in every iteration
    Snapshot& getSnapshot();
    void applySnapshot(const Snapshot& snapshot);
};


#endif //SFML_TEMPLATE_LABEL_H