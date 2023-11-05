//
// Created by Tammy S on 11/2/23.
//

#ifndef SFML_TEMPLATE_MOUSEEVENTS_CPP
#define SFML_TEMPLATE_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return sf::Mouse::isButtonPressed(sf::Mouse::Left) && object.getGlobalBounds().contains(mpos);
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    return event.mouseButton.button == sf::Mouse::Left;
}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Time elapsed = clock.getElapsedTime();
            if (clicks == 0 || elapsed.asMilliseconds() > 500) { // Adjust the time threshold as needed
                clicks = 1;
                clock.restart();
            } else {
                clicks++;
                clock.restart();
                if (clicks == 2) {
                    std::cout << "Double-click detected" << std::endl;
                    clicks = 0; // Reset the click count
                    return true;
                }
            }
        }
    }
    return false;
}

template<class T>
bool MouseEvents<T>::mouseTripleClicked(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Time elapsed = clock.getElapsedTime();
            if (clicks == 0 || elapsed.asMilliseconds() > 500) { // Adjust the time threshold as needed
                clicks = 1;
                clock.restart();
            } else {
                clicks++;
                clock.restart();
                if (clicks == 3) {
                    std::cout << "Triple-click detected" << std::endl;
                    clicks = 0; // Reset the click count
                    return true;
                }
            }
        }
    }
    return false;
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    return false;
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return (object.getGlobalBounds().contains(mpos));
}

template<class T>
void MouseEvents<T>::countClicks(sf::Event event) {
    int count = 0;

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Time elapsed = clock.getElapsedTime();
            if (elapsed.asMilliseconds() > 500) { // Adjust the time threshold as needed
                clicks++;
                clock.restart();
            }

        }
    }
}

#endif //SFML_TEMPLATE_MOUSEEVENTS_CPP