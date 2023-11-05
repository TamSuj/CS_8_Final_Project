//
// Created by Tammy S on 11/2/23.
//

#ifndef SFML_TEMPLATE_HISTORY_H
#define SFML_TEMPLATE_HISTORY_H

#include <stack>
//#include <string>
//#include "Snapshot.h"
#include "GUIComponent.h"
#include "KeyboardShortcut.h"

struct HistoryNode
{
    Snapshot snapshot;
    GUIComponent* component;

};


class History  {
    static std::stack<HistoryNode> stack;

public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
    static void clearHistory();

};




#endif //SFML_TEMPLATE_HISTORY_H
