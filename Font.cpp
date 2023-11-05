//
// Created by Tammy S on 10/5/23.
//

#include "Font.h"

std::map<fontEnum, sf::Font> Font::fonts;

void Font::loadFont(fontEnum font) {
    fonts[font].loadFromFile(getFontPath(font));

}
std::string Font::getFontPath(fontEnum font) {
    switch(font){
        case OPEN_SANS:
            return "Font/OpenSans.ttf";
        case NOTO_SANS:
            return "Font/NotoSans.ttf";
        case LATO:
            return "Font/Lato-Bold.ttf";
        case PRODUCT_SANS:
            return "Font/ProductSans.ttf";

    }

//    std::string f[] = {"Font/OpenSans.ttf"};
//    return f[font];
}

sf::Font &Font::getFont(fontEnum font){
    loadFont(font);
    return fonts[font];
}