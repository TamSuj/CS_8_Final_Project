//
// Created by Tammy S on 10/31/23.
//

#include "Box.h"

Box::Box() : Box(BOX_DEFAULT_SIZE){

}

Box::Box(const sf::Vector2f &size) : box(size){

}

void Box::eventHandler(sf::RenderWindow &window, sf::Event event) {
//    If mouse is in the bound of the box
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(box.getGlobalBounds().contains(mpos))
        enableState(HOVERED);
    else
        disableState(HOVERED);

}

void Box::update() {
    if(checkState(HOVERED))
        box.setFillColor(LIGHT_BLUE); //Light blue
    else
        box.setFillColor(DARK_BLUE); //Dark blue
}

void Box::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    if(!checkState(HIDDEN))
        window.draw(box);

}

Snapshot &Box::getSnapshot() {
    Snapshot snapshot("Box");
    return snapshot;
}

void Box::applySnapshot(const Snapshot &snapshot) {

}
