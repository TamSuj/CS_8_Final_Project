//
// Created by Tammy S on 10/31/23.
//

#ifndef SFML_TEMPLATE_GUICOMPONENT_H
#define SFML_TEMPLATE_GUICOMPONENT_H
#include <SFML/Graphics.hpp>
#include "SnapshotInterface.h"
#include "States.h"


class GUIComponent : public sf::Sprite, public States, public SnapshotInterface{
public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0; //Call in every iteration
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //SFML_TEMPLATE_GUICOMPONENT_H
