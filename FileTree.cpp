//
// Created by Tammy S on 11/16/23.
//
#ifndef SFML_TEMPLATE_FILETREE_CPP
#define SFML_TEMPLATE_FILETREE_CPP

#include "FileTree.h"

template<typename T>
FileTree<T>::FileTree() {

}

template<typename T>
FileTree<T>::FileTree(const T &item, bool isFileNode) : name(item), isFile(isFileNode) {

}

template<typename T>
void FileTree<T>::addNode(FileTree *node) {
    children.push_back(node);

}

template<typename T>
void FileTree<T>::printTree(FileTree<T> *node, int depth) {
//Only print if root is not nullptr
    if (node != nullptr) {
        // Print the current node (directory or file)
        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";  // Adjust indentation for better visualization
        }

        std::cout << (node->isFile ? "File: " : "Directory: ") << node->name << std::endl;

        // Recursively print children
        for (FileTree<T> *child: node->children) {
            printTree(child, depth + 1);
        }
    }

}

template<typename T>
void FileTree<T>::fakeTree() {
    // Creating a file system tree of strings
    FileTree<std::string>* root = new FileTree<std::string>("Desktop", false);

    // Adding directories and files
    FileTree<std::string>* documents = new FileTree<std::string>("Documents", false);
    FileTree<std::string>* pictures = new FileTree<std::string>("Downloads", false);
    FileTree<std::string>* file1 = new FileTree<std::string>("file1.txt", true);
    FileTree<std::string>* file2 = new FileTree<std::string>("file2.jpg", true);

    root->addNode(documents);
    root->addNode(pictures);
    documents->addNode(file1);
    pictures->addNode(file2);

    // Print the file tree
    printTree(root);
}

#endif