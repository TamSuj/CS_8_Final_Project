//
// Created by Tammy S on 11/2/23.
//

#include "KeyboardShortcut.h"

KeyboardShortcut::KeyboardShortcut() {

}

bool KeyboardShortcut::isUndo() {
    //check if command + Z is pressed
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
    && sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
}

bool KeyboardShortcut::isScreenshot() {
    //check if command + P is pressed
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
           && sf::Keyboard::isKeyPressed(sf::Keyboard::P);
}
