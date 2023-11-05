//
// Created by Tammy S on 11/2/23.
//

#include "TextInput.h"

TextInput::TextInput() : TextInput(BOX_DEFAULT_SIZE) { }

TextInput::TextInput(const sf::Vector2f &pos, const sf::Vector2f &size)
: cursor(sf::milliseconds(300)), box(BOX_DEFAULT_SIZE), text("") {
    box.setPosition(pos);
    box.setFillColor(sf::Color::White);
    box.setOutlineColor(sf::Color(179, 179, 179));
    box.setOutlineThickness(1);
    box.setSize(size);
    text.setPosition({box.getPosition().x + 10,box.getPosition().y+10});
    cursor.setPosition({box.getPosition().x + DEFAULT_TEXT_SIZE/3, box.getPosition().y +7});
}

void TextInput::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(checkState(CLICKED))
        text.eventHandler(window, event);

    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(box.getGlobalBounds().contains(mpos)) {
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            enableState(CLICKED);
        }
        else
            enableState(HOVERED);
    }
    else {
        disableState(HOVERED);
        disableState(CLICKED);
    }
}

void TextInput::update() {
    cursor.update();

    if(!text.empty())
        cursor.setPosition({text.getPosition().x + DEFAULT_TEXT_SIZE/3, text.getPosition().y-3});

//    Resize box if text is too long
    if(text.getPosition().x > box.getSize().x) {
        box.setSize({text.getPosition().x - 2 * DEFAULT_TEXT_SIZE, box.getSize().y});
    }

    if(checkState(HOVERED)) {
        box.setFillColor(sf::Color(240, 240, 240)); //Light grey
        box.setOutlineColor(sf::Color(179, 179, 179));
    }else
        box.setFillColor(sf::Color::White); //Dark grey

    if(checkState(CLICKED))
        cursor.setColor(DEFAULT_TEXT_COLOR);
    else
        cursor.setColor(sf::Color::Transparent);


}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);

//    Only draw cursor if the user click on the box
    if(checkState(CLICKED)) {
        window.draw(cursor);
    }

    text.draw(window, states);
}

Snapshot &TextInput::getSnapshot() {
    Snapshot snapshot(text.getString());
    return snapshot;
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    text.setString(snapshot.getString());
}

//sf::Vector2f TextInput::getGlobalBounds() const {
//    return box.getGlobalBounds().getSize();
//}
//
//bool TextInput::contains(sf::Vector2f point) const {
//    return box.getGlobalBounds().contains(point);
//}
