//
// Created by Tammy S on 11/7/23.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
    box.setPosition(pos);
    box.setSize(size);
    box.setFillColor(color);
    box.setOutlineThickness(1);

    dropdown.setPosition({pos.x, pos.y + size.y});
    dropdown.setSize({size.x, size.y * 2});
    dropdown.setFillColor(sf::Color::Red);
    dropdown.setOutlineThickness(1);

}

void DropdownMenu::setPosition(const sf::Vector2f &pos) {
    box.setPosition(pos);
}

void DropdownMenu::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(box.getGlobalBounds().contains(mpos)) {
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            enableState(CLICKED);
        }
        else
            enableState(HOVERED);
    }
    else {
        disableState(HOVERED);
        disableState(CLICKED);
    }
}

void DropdownMenu::update() {
//    box.update();

    if(checkState(CLICKED)) {
        disableState(HIDDEN);
    }
    else {
        enableState(HIDDEN);
    }
}

Snapshot &DropdownMenu::getSnapshot(){
    Snapshot snapshot("DropdownMenu");
    return snapshot;
}

void DropdownMenu::applySnapshot(const Snapshot &snapshot) {

}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!checkState(HIDDEN)) {
        std::cout << "Draw dropdown" << std::endl;
        window.draw(dropdown);
    }

    window.draw(box);

}
