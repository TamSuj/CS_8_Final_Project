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
#include <iostream>

struct HistoryNode
{
    Snapshot snapshot;
    GUIComponent* component;
};


class History  {
    static std::stack<HistoryNode> stack;

public:
    static void pushHistory( const HistoryNode& snapshot);
    static HistoryNode& createHistoryNode(Snapshot& snapshot, GUIComponent* component);
    static HistoryNode& topHistory();
    static void popHistory();
    static bool isEmpty();
    static Snapshot top();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
    static void clearHistory();
    static void push(const Snapshot& snapshot, GUIComponent* component);

};




#endif //SFML_TEMPLATE_HISTORY_H
