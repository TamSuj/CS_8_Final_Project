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

class DropdownList : public sf::Text, public GUIComponent {
    std::list<Letter> textList;
    sf::Vector2f position = {0,0};
    int lineHeight = DEFAULT_TEXT_SIZE + 10;

public:
    DropdownList();
    DropdownList(const std::string &message);
    DropdownList(const std::string &message, sf::Vector2f pos);
    void push(char text);
    void push(const std::string& text);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void clear();
    void setPosition(sf::Vector2f pos);
    bool empty();
    sf::Vector2f getPosition();
    sf::Vector2f getPosition() const;
    void setLineHeight(const int height);

    typedef std::list<Letter>::iterator iterator;

    iterator begin();
    iterator end();

    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override; //Call in every iteration

    Snapshot& getSnapshot() override;
    void applySnapshot(const Snapshot& snapshot) override;

    bool blankLetter();
};


#endif //SFML_TEMPLATE_DROPDOWNLIST_H
