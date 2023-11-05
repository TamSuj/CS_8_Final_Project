//
// Created by Tammy S on 10/5/23.
//

#ifndef SFML_TEMPLATE_FONT_H
#define SFML_TEMPLATE_FONT_H
#include <SFML/Graphics.hpp>

#include <iostream>
#include <map>
#include "FontEnum.h"

class Font {
    static std::map<fontEnum, sf::Font> fonts;
    static void loadFont(fontEnum font);
    static std::string getFontPath(fontEnum font);
public:
    static sf::Font& getFont(fontEnum font);
};


#endif //SFML_TEMPLATE_FONT_H
