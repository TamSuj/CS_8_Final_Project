//
// Created by Tammy S on 11/18/23.
//

#ifndef SFML_TEMPLATE_FILE_H
#define SFML_TEMPLATE_FILE_H

#include "fileDropdown.h"

class File {
    std::vector<fileDropdown*> fileList;

    sf::Vector2f pos;

public:
    File(const std::string& filepath);
    void push_back(std::vector<std::string> list);

};


#endif //SFML_TEMPLATE_FILE_H
