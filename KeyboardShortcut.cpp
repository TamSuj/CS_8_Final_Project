//
// Created by Tammy S on 11/2/23.
//

#include "KeyboardShortcut.h"

bool KeyboardShortcut::isUndo() {
    //check if command + Z is pressed
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem))
           && sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
}

bool KeyboardShortcut::isScreenshot() {
    //check if command + P is pressed
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem))
           && sf::Keyboard::isKeyPressed(sf::Keyboard::P);
}

bool KeyboardShortcut::isSave() {
    //check if command + S is pressed
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem))
           && sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

bool KeyboardShortcut::isSelectAll() {
    //check if command + A is pressed
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem))
           && sf::Keyboard::isKeyPressed(sf::Keyboard::A);
}

bool KeyboardShortcut::isEnter() {
    //check enter button is pressed
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
}
