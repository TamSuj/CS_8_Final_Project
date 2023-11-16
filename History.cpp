//
// Created by Tammy S on 11/2/23.
//

#include "History.h"

std::stack<HistoryNode> History::stack;

void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);
//    std::cout << "Stack pushed: " << stack.top().snapshot.getString() << std::endl;
}

HistoryNode& History::createHistoryNode(Snapshot &snapshot, GUIComponent *component) {
    HistoryNode* n = new HistoryNode;
    n->snapshot = snapshot;
    n->component = component;

    std::cout << "new HistoryNode->snapshot: " << n->snapshot.getString() << std::endl;
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
    if (KeyboardShortcut::isUndo() && !isEmpty()) {
        std::cout << "Undo, applying " << top().getString() << std::endl;
        topHistory().component->applySnapshot(topHistory().snapshot);
        popHistory();
    }

}

void History::clearHistory() {
    while(!stack.empty())
        stack.pop();
}

void History::push(const Snapshot& snapshot, GUIComponent* component) {
//    std::cout << "history push " << snapshot.getString() << std::endl;

//    assert(snapshot.getString() != "");


//    std::string s = snapshot.getString();
//    Snapshot snapshot2(s);
//    std::cout << "pushed received: " << snapshot2.getString() << std::endl;
//
//    std::cout << "History pushed: " << snapshot.getString() << std::endl;
//
//    HistoryNode n = createHistoryNode(snapshot, component);
//    History::pushHistory(n);

//    2. Works for a bit but crash at the end
//    auto text = snapshot.getString();
//    std::cout << "History pushed: " << text << std::endl;
//    History::pushHistory(createHistoryNode(Snapshot(text), component));

//    std::cout << "History pushed: " << snapshot.getString() << std::endl;
//
    History::pushHistory({snapshot, component});

}
