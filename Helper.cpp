//
// Created by Tammy S on 11/2/23.
//
#ifndef SFML_TEMPLATE_HELPER_CPP
#define SFML_TEMPLATE_HELPER_CPP

#include "Helper.h"

template<typename T>
void Helper<T>::centerText(const T &obj, sf::Text text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});
}

/*
std::cout << "menuArea: " << menuArea.x << " " << menuArea.y << std::endl;
std::cout << "mousePos: " << mousePos.x << " " << mousePos.y << std::endl;
*/
#endif