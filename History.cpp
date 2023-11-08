//
// Created by Tammy S on 11/2/23.
//

#include "History.h"

std::stack<HistoryNode> History::stack;

void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);
}

HistoryNode& History::createHistoryNode(const Snapshot &snapshot, GUIComponent *component) {
    HistoryNode* n = new HistoryNode;
    n->snapshot = snapshot.getString();
    n->component = component;

//    std::cout << "new HistoryNode->snapshot: " << n->snapshot.getString() << std::endl;
    return *n;
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    stack.pop();
}

bool History::isEmpty() {
    return stack.empty();
}

Snapshot History::top() {
    return stack.top().snapshot;
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (KeyboardShortcut::isUndo()) {
        if (!stack.empty()) {
            HistoryNode top = topHistory();
            std::cout << "Undo, applying " << top.snapshot.getString() << std::endl;
            topHistory().component->applySnapshot(top.snapshot);
            popHistory();
        }
    }

}

void History::clearHistory() {
    while(!stack.empty())
        stack.pop();
}

void History::push(Snapshot& snapshot, GUIComponent* component) {
    History::pushHistory(History::createHistoryNode(snapshot, component));
}
