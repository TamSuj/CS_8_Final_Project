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

class Box : public GUIComponent {
sf::RectangleShape box;

public:
    Box();
    Box(const sf::Vector2f &size);

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
