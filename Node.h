//
// Created by Tammy S on 11/17/23.
//

#ifndef SFML_TEMPLATE_NODE_H
#define SFML_TEMPLATE_NODE_H

#include <vector>

template <typename T>
class Node {
public:
    T data;
    std::vector<Node*> children;

    Node(T data);
};

#include "Node.cpp"

#endif //SFML_TEMPLATE_NODE_H
