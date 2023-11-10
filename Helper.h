//
// Created by Tammy S on 11/2/23.
//

#ifndef SFML_TEMPLATE_HELPER_H
#define SFML_TEMPLATE_HELPER_H

#include <SFML/Graphics/Text.hpp>
#include <cmath>

template <typename T>
class Helper {
public:
    void static centerText(const T &obj, sf::Text text);
};

#include "Helper.cpp"
#endif //SFML_TEMPLATE_HELPER_H
