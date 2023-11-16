//
// Created by Tammy S on 11/13/23.
//

#ifndef SFML_TEMPLATE_HOWTOUSE_H
#define SFML_TEMPLATE_HOWTOUSE_H

#include "Box.h"
#include "GUIComponent.h"

class HowToUse : public GUIComponent{
    Box box;
    sf::Vector2f size = sf::Vector2f(300, 300);

    std::vector<std::string> content = {"1. Do XYZ.",
                                        "2. Do ABC.",
                                        "3. Do dadada.",
                                        "4. Pray."};

    std::vector<Label> text;
    int lineHeight = 40;
public:
    HowToUse(sf::Vector2f position = sf::Vector2f(0, 0));

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(); //Call in every iteration
    Snapshot getSnapshot();
    void applySnapshot(const Snapshot& snapshot);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //SFML_TEMPLATE_HOWTOUSE_H
