//
// Created by Tammy S on 10/31/23.
//

#ifndef SFML_TEMPLATE_BOX_H
#define SFML_TEMPLATE_BOX_H

//#include <SFML/Graphics.hpp>
#include "States.h"
#include "GUIComponent.h"
#include "Constants.h"
#include "SnapshotInterface.h"
#include "Label.h"
#include "Helper.h"

class Box : public GUIComponent {
sf::RectangleShape box;
Label text;

public:
    Box();
    Box(const sf::Vector2f &size);
    Box(const std::string& message, const sf::Vector2f &size);

    void setSize(sf::Vector2f size);
    void setFillColor(sf::Color color);
    void setOutlineColor(sf::Color color);
    void setOutlineThickness(const int &thickness);
    void setPosition(const sf::Vector2f& pos);
    void setText(const std::string &message);

    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    Label getText() const;

//    Event handler
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(); //Call in every iteration
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // this function will return a snapshot of the object's current state
    Snapshot& getSnapshot();

    // this function will apply a snapshot to the object.
    //This will revert the object back to the state that has been recorded in the snapshot
    void applySnapshot(const Snapshot& snapshot);
};


#endif //SFML_TEMPLATE_BOX_H
