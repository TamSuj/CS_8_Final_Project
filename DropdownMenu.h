//
// Created by Tammy S on 11/7/23.
//

#ifndef SFML_TEMPLATE_DROPDOWNMENU_H
#define SFML_TEMPLATE_DROPDOWNMENU_H

#include "GUIComponent.h"
#include "Box.h"
#include <iostream>
#include "MouseEvents.h"

class DropdownMenu : public GUIComponent{
    Box box;
    Box dropdown;

public:
    DropdownMenu(sf::Vector2f pos, sf::Vector2f size, sf::Color color = LIGHT_BLUE);
    void setPosition(const sf::Vector2f& pos);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(); //Call in every iteration

    Snapshot& getSnapshot();
    void applySnapshot(const Snapshot& snapshot);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //SFML_TEMPLATE_DROPDOWNMENU_H
