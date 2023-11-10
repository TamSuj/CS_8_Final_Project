//
// Created by Tammy S on 11/2/23.
//

#ifndef SFML_TEMPLATE_EVENTHANDLER_H
#define SFML_TEMPLATE_EVENTHANDLER_H

#include <SFML/Graphics.hpp>
#include "KeyboardShortcut.h"
#include <iostream>

class EventHandler {
public:
    EventHandler();
    static void basicEventHandler(sf::RenderWindow& window, sf::Event event);
    static void screenshot(sf::RenderWindow& window, sf::Event event, std::string filename);
/*
 * //Resize window
    if (event.type == sf::Event::Resized)
    std::cout << "woah, the screen was resized!" << std::endl;

//    Take screenshot
    else if( (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) && sf::Keyboard::isKeyPressed(sf::Keyboard::P) ){
               //Command + P (Screenshot)
                sf::Texture texture;
                texture.create(window.getSize().x, window.getSize().y);
                texture.update(window);
                if (texture.copyToImage().saveToFile(filename))
                    std::cout << "screenshot saved to " << filename << std::endl;
            }
*/
};


#endif //SFML_TEMPLATE_EVENTHANDLER_H
