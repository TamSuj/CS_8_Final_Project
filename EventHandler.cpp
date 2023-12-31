//
// Created by Tammy S on 11/2/23.
//

#include "EventHandler.h"

void EventHandler::basicEventHandler(sf::RenderWindow& window, sf::Event event) {
    //If esc or close button is pressed, close the window
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();

}

void EventHandler::screenshot(sf::RenderWindow &window, sf::Event event, std::string filename) {
    if(KeyboardShortcut::isScreenshot()) {
        sf::Texture texture;
        texture.create(window.getSize().x, window.getSize().y);
        texture.update(window);

        if (texture.copyToImage().saveToFile("Output/" + filename))
            std::cout << "screenshot saved to " << filename << std::endl;

    }
}
