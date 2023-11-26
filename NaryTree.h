//
// Created by Tammy S on 11/20/23.
//

#ifndef SFML_TEMPLATE_NARYTREE_H
#define SFML_TEMPLATE_NARYTREE_H

#include "treeNode.h"
#include <iostream>

#include <vector>
#include <queue>

class NaryTree {
    treeNode* root = nullptr;
    void push(treeNode* parent, treeNode* child);
    void print(treeNode* node); //Print as path
    void print(treeNode* node, int); //Print as tree
    treeNode* find(treeNode* parent, const std::string &data); //Search for a path

public:
    void fakeNaryTree();
    void push(const std::string& path); //Pass something like "Documents/CS 8/Project 2"
    void printPath();
    void printTree();

};


#endif //SFML_TEMPLATE_NARYTREE_H
