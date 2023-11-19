//
// Created by Tammy S on 11/18/23.
//

#ifndef SFML_TEMPLATE_FILEDROPDOWN_H
#define SFML_TEMPLATE_FILEDROPDOWN_H

#include "GUIComponent.h"
#include "Constants.h"
#include "Box.h"
#include "History.h"
#include "FileTree.h"

class fileDropdown : public GUIComponent {
    std::vector<std::string> lists;
    sf::Vector2f position = {0,0};
    sf::Vector2f size;

    Box box;
    std::vector<Box*> dropdowns;
    sf::Texture img;
    sf::Sprite sprite;

    bool changeWhenClicked = true;
    sf::Color highlightColor = sf::Color(199, 199, 199);

    FileTree<std::string> *tree;
public:
    fileDropdown(FileTree<std::string> &tree, sf::Vector2f pos = {0,50}, sf::Vector2f size = {150,200}, sf::Color color = sf::Color::White);

    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);
    void setHeader(const std::string& message);
    void setColor(sf::Color color);
    void setHighlightColor(sf::Color color);

    sf::Vector2f getPosition();
    sf::Vector2f getSize();

    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override; //Call in every iteration
    Snapshot getSnapshot() override;
    void applySnapshot(const Snapshot& snapshot) override;
};


#endif //SFML_TEMPLATE_FILEDROPDOWN_H
