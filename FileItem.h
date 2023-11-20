//
// Created by Tammy S on 11/19/23.
//

#ifndef SFML_TEMPLATE_FILEITEM_H
#define SFML_TEMPLATE_FILEITEM_H

#include "Box.h"
#include "Image.h"

class FileItem : public Box
{

public:
    //Constructors
    FileItem();
    FileItem(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position);

    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the size of the item
    sf::Vector2f getPosition() const;
    //sets the position of the item
    void setPosition(sf::Vector2f pos);
    //uses an enum to change the icon to a folder or file
    void setIcon(Image::image icon);

private:
    //this is the folder or file icon
    sf::Sprite icon;
    float padding = 5;
};




#endif //SFML_TEMPLATE_FILEITEM_H
