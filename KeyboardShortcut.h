//
// Created by Tammy S on 11/2/23.
//

#ifndef SFML_TEMPLATE_KEYBOARDSHORTCUT_H
#define SFML_TEMPLATE_KEYBOARDSHORTCUT_H

#include <SFML/Window/Keyboard.hpp>

class KeyboardShortcut {

public:
    static bool isUndo();
    static bool isScreenshot();
    static bool isSave();
    static bool isSelectAll();
    static bool isEnter();
    static bool isZoomIn();
    static bool isZoomOut();
};


#endif //SFML_TEMPLATE_KEYBOARDSHORTCUT_H
