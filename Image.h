//
// Created by Tammy S on 11/19/23.
//

#ifndef SFML_TEMPLATE_IMAGE_H
#define SFML_TEMPLATE_IMAGE_H

#include <SFML/Graphics.hpp>

class Image {
public:
    enum image {
        folder,
        file
    };
public:
    Image();
    static sf::Image folderImage;
    static sf::Image fileImage;
};


#endif //SFML_TEMPLATE_IMAGE_H
