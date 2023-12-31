//
// Created by Tammy S on 11/10/23.
//

#ifndef SFML_TEMPLATE_DROPDOWNMENUS_H
#define SFML_TEMPLATE_DROPDOWNMENUS_H

#include "GUIComponent.h"
#include "Constants.h"
#include "Box.h"
#include "History.h"

class DropdownMenus : public GUIComponent{
    std::vector<std::string> lists;
    sf::Vector2f position = {0,0};
    sf::Vector2f size;

    Box box;
    std::vector<Box*> dropdowns;

    bool changeWhenClicked = true;
    sf::Color highlightColor = sf::Color(227, 227, 227);
public:
    DropdownMenus(const std::string &text, sf::Vector2f pos, sf::Vector2f size, sf::Color color = LIGHT_BLUE, bool changeWhenClicked = true);
    DropdownMenus(const std::vector<std::string> message, sf::Vector2f pos, sf::Vector2f size, sf::Color color = LIGHT_BLUE, bool changeWhenClicked = true);

    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);
    void setHeader(const std::string& message);
    void setColor(sf::Color color);
    void setHighlightColor(sf::Color color);

    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    std::string getHeader();

    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override; //Call in every iteration
    Snapshot getSnapshot() override;
    void applySnapshot(const Snapshot& snapshot) override;

    void disableChangeWhenClicked();
    void enableChangeWhenClicked();
};


#endif //SFML_TEMPLATE_DROPDOWNMENUS_H
