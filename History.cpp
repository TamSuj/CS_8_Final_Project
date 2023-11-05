//
// Created by Tammy S on 11/2/23.
//

#include "History.h"

std::stack<HistoryNode> History::stack;

void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    stack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (KeyboardShortcut::isUndo()) {
        if (!stack.empty()) {
            HistoryNode top = topHistory();
            top.component->applySnapshot(top.snapshot);
            popHistory();
        }
    }

}

void History::clearHistory() {
    while(!stack.empty())
        stack.pop();
}
