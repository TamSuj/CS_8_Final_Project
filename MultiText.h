//
// Created by Tammy S on 10/17/23.
//

#ifndef SFML_TEMPLATE_MULTITEXT_H
#define SFML_TEMPLATE_MULTITEXT_H

#include "SFML/Graphics.hpp"
#include <list>
#include "Letter.h"
#include "GUIComponent.h"
#include "States.h"

class MultiText : public sf::Text, public GUIComponent {
std::list<Letter> textList;
sf::Vector2f position = {0,0};

public:
    MultiText();
    MultiText(const std::string &message);
    MultiText(const std::string &message, sf::Vector2f pos);
    void push(char text);
    void push(const std::string& text);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void clear();
    void setPosition(sf::Vector2f pos);
    bool empty();
    sf::Vector2f getPosition();
    sf::Vector2f getPosition() const;

    typedef std::list<Letter>::iterator iterator;

    iterator begin();
    iterator end();

    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override; //Call in every iteration

    Snapshot& getSnapshot() override;
    void applySnapshot(const Snapshot& snapshot) override;

};


#endif //SFML_TEMPLATE_MULTITEXT_H
