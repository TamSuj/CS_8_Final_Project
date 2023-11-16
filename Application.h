//
// Created by Tammy S on 10/18/23.
//

#ifndef SFML_TEMPLATE_APPLICATION_H
#define SFML_TEMPLATE_APPLICATION_H

#include "SFML/Graphics.hpp"
#include "Constants.h"
#include "MultiText.h"
#include "GUIComponent.h"
#include <vector>

#include "Box.h"
#include "EventHandler.h"
#include "TextInput.h"
#include "Label.h"
#include "MouseEvents.h"

#include "DropdownMenus.h"
#include "HowToUse.h"
#include "MenuBar.h"

class Application {
    static std::vector<GUIComponent*> components;
public:
    Application();
    static void run();
    static void addComponent(GUIComponent& component);
};


#endif //SFML_TEMPLATE_APPLICATION_H
