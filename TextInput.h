//
// Created by Tammy S on 11/2/23.
//

#ifndef SFML_TEMPLATE_TEXTINPUT_H
#define SFML_TEMPLATE_TEXTINPUT_H

#include "GUIComponent.h"
#include "MultiText.h"
#include "Cursor.h"
#include "History.h"
/*
A box for the user to type in
A Cursor  with the following features:
Only visible when the mouse clicks in the box
Hides when the mouse is clicked outside the box
Blinks n and off when visible
Always stays next to the last letter typed in the box
A label that describes what the text input is for (i.e First Name and Last Name, from the link above)
When the words int, char, double and float are typed, the color of the word changes to blue
When an operator is typed, it is changed to green
When a number is typed, it is changed to red
Since we are unable to change individual letter to different colors in a sf::Text object,
 you must use your MultiText class. Since each individual character is in its own sf::Text object,
 you now can apply a color to individual characters. This functionality is not trivial, start working on it ASAP.

 */
class TextInput : public GUIComponent {
    sf::RectangleShape box;
    Cursor cursor;
    MultiText text;

public:
    TextInput();
    TextInput(const sf::Vector2f &pos, const sf::Vector2f &size = {150, 50});

    //    Event handler
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(); //Call in every iteration
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot getSnapshot();
    void applySnapshot(const Snapshot& snapshot);

//    sf::Vector2f getGlobalBounds() const;
//    bool contains(sf::Vector2f point) const;
};


#endif //SFML_TEMPLATE_TEXTINPUT_H

