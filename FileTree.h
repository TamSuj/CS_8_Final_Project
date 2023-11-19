//
// Created by Tammy S on 11/16/23.
//

#ifndef SFML_TEMPLATE_FILETREE_H
#define SFML_TEMPLATE_FILETREE_H

#include <vector>
#include <iostream>
#include <sfml/Graphics.hpp>

template <typename T>
class FileTree {
public:
    T name;
    bool isFile;
    std::vector<FileTree*> children;

    FileTree();
    FileTree(const T& item, bool isFileNode = false);

    // Function to add a child node
    void addNode(FileTree* node);
    void printTree(FileTree<T>* root, int depth = 0);
    void fakeTree();

//    void drawTree(FileTree<T>* root, int depth = 0, sf::RenderTarget& window, sf::RenderStates states);
};

#include "FileTree.cpp"
#endif //SFML_TEMPLATE_FILETREE_H
