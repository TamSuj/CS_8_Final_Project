//
// Created by Tammy S on 10/18/23.
//

#ifndef SFML_TEMPLATE_LETTER_H
#define SFML_TEMPLATE_LETTER_H

#include "SFML/Graphics.hpp"
#include "Font.h"
#include "Constants.h"

class Letter : public sf::Text{
public:
    Letter();
    Letter(char letter);

    std::string getChar();
};


#endif //SFML_TEMPLATE_LETTER_H
