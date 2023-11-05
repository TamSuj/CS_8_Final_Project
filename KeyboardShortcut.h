//
// Created by Tammy S on 11/2/23.
//

#ifndef SFML_TEMPLATE_KEYBOARDSHORTCUT_H
#define SFML_TEMPLATE_KEYBOARDSHORTCUT_H

#include <SFML/Window/Keyboard.hpp>

class KeyboardShortcut {

public:
    KeyboardShortcut();
    static bool isUndo();
    static bool isScreenshot();
};


#endif //SFML_TEMPLATE_KEYBOARDSHORTCUT_H
