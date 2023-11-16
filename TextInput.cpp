//
// Created by Tammy S on 11/2/23.
//

#include "TextInput.h"

TextInput::TextInput() : TextInput(BOX_DEFAULT_SIZE) { }

TextInput::TextInput(const sf::Vector2f &pos, const sf::Vector2f &size)
: cursor(sf::milliseconds(400)), box(BOX_DEFAULT_SIZE), text("") {
    box.setPosition(pos);
    box.setFillColor(TEXT_BOX_BG_COLOR);
    box.setOutlineColor(TEXT_BOX_OUTLINE_COLOR);
    box.setOutlineThickness(1);
    box.setSize(size);
    text.setPosition({box.getPosition().x + 10,box.getPosition().y+10});
    cursor.setPosition({box.getPosition().x + DEFAULT_TEXT_SIZE/3, box.getPosition().y +7});
}

void TextInput::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(checkState(CLICKED)) {
        text.eventHandler(window, event);

        if (sf::Event::TextEntered == event.type) {
            History::push(getSnapshot(), this);
        }
    }
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
    text.update();
    cursor.update();

    if(!text.empty())
        cursor.setPosition({text.getPosition().x + DEFAULT_TEXT_SIZE / 3, text.getPosition().y - 3});
    else
        cursor.setPosition({box.getPosition().x + DEFAULT_TEXT_SIZE / 3, box.getPosition().y + 7});


//    Resize box if text is too long
//    if(text.getPosition().x > box.getSize().x)
//        box.setSize({text.getPosition().x - 2 * DEFAULT_TEXT_SIZE, box.getSize().y});

//    Change bg color and outline color of the box if hovered
    if(checkState(HOVERED)) {
        box.setFillColor(sf::Color(247, 247, 247)); //Light grey
        box.setOutlineColor(sf::Color(179, 179, 179));
    }else
        box.setFillColor(sf::Color::White); //Dark grey

    if(checkState(CLICKED)) {
        cursor.setColor(DEFAULT_TEXT_COLOR);
        box.setOutlineThickness(2);
        box.setOutlineColor(DARK_BLUE);
    }
    else {
        cursor.setColor(sf::Color::Transparent);
        box.setOutlineThickness(1);
        box.setOutlineColor(TEXT_BOX_OUTLINE_COLOR);
    }


}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);

//    Only draw cursor if the user click on the box
    if(checkState(CLICKED)) {
        window.draw(cursor);
    }

    text.draw(window, states);
}

Snapshot TextInput::getSnapshot() {
    Snapshot snapshot(text.getString());
    std::cout << " text input snapshot: " << snapshot.getString() << std::endl;
    return snapshot;
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    std::cout << "applying snapshot" << snapshot.getString() << std::endl;
    text.setString(snapshot.getString());
}

//sf::Vector2f TextInput::getGlobalBounds() const {
//    return box.getGlobalBounds().getSize();
//}
//
//bool TextInput::contains(sf::Vector2f point) const {
//    return box.getGlobalBounds().contains(point);
//}
