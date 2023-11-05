//
// Created by Tammy S on 11/2/23.
//

#include "EventHandler.h"

EventHandler::EventHandler() {

}

void EventHandler::basicEventHandler(sf::RenderWindow& window, sf::Event event) {
    //If esc or close button is pressed, close the window
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        //Do something when enter is pressed
    }
}
