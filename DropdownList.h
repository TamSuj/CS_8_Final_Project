//
// Created by Tammy S on 11/9/23.
//

#ifndef SFML_TEMPLATE_DROPDOWNLIST_H
#define SFML_TEMPLATE_DROPDOWNLIST_H

#include "SFML/Graphics.hpp"
#include <vector>
#include <list>
#include "Letter.h"
#include "GUIComponent.h"
#include "States.h"
#include "KeyboardShortcut.h"
#include "History.h"
#include "Box.h"
#include "Label.h"
#include "Helper.h"

class DropdownList : public sf::Text, public GUIComponent {
    std::list<Letter> textList;
    sf::Vector2f position = {0,0};
    int lineHeight = 2 * DEFAULT_TEXT_SIZE;

    Box header;
    std::vector<std::string> lists;

    sf::Vector2f menuArea;
    bool changeWhenClicked = true;

public:
    DropdownList();
    DropdownList(const std::string &message);
    DropdownList(const std::vector<std::string> &messageVec, sf::Vector2f pos, sf::Vector2f size);
    void push(const std::string& text);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void clear();
    void setPosition(sf::Vector2f pos);
    void setColor(sf::Color color);
    bool empty();
    sf::Vector2f getPosition();
    sf::Vector2f getPosition() const;
    void setLineHeight(const int height);
    void setHeader(const std::string &message);
    sf::Vector2f getSize();

    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override; //Call in every iteration

    Snapshot& getSnapshot() override;
    void applySnapshot(const Snapshot& snapshot) override;
    void disableChangeWhenClicked();
};


#endif //SFML_TEMPLATE_DROPDOWNLIST_H
