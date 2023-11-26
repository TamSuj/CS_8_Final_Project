//
// Created by Tammy S on 11/16/23.
//

#ifndef SFML_TEMPLATE_FILETREE_H
#define SFML_TEMPLATE_FILETREE_H

#include <vector>
#include <iostream>
#include "GUIComponent.h"

#include "MenuBar.h"

template <typename T>
class FileTree : public GUIComponent{
    MenuBar* header;
    std::vector<MenuBar*> dropdowns;
    int margin = 50;
    sf::Color highlightColor = sf::Color(227, 227, 227);
    sf::Color fileBGColor = sf::Color::White;

    sf::Texture folderTexture;
    sf::Texture fileTexture;
    sf::Sprite folder;
    sf::Sprite file;

    void init();
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

    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override; //Call in every iteration
    Snapshot getSnapshot() override;
    void applySnapshot(const Snapshot& snapshot) override;

    void setHeaderColor(sf::Color color);

};

#include "FileTree.cpp"
#endif //SFML_TEMPLATE_FILETREE_H
