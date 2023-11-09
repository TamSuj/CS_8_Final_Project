//
// Created by Tammy S on 11/9/23.
//

#include "DropdownList.h"

//dropdown.setSize({size.x, size.y * 2});
DropdownList::DropdownList() : DropdownList("") { }

DropdownList::DropdownList(const std::string &message) {
    push(message);
}

DropdownList::DropdownList(const std::string &message, sf::Vector2f pos) {
    push(message);
    setPosition(pos);
}

void DropdownList::setPosition(sf::Vector2f pos) {
    position = pos;
}

void DropdownList::push(char text){
    if (text == '\n') {
        Letter letter('\0');
        letter.setFillColor(sf::Color::Transparent);
        letter.setPosition(position.x, textList.back().getPosition().y + lineHeight);
        textList.push_back(letter);
    }
    else{
        if (textList.empty()) {
            Letter letter(text);
            letter.setPosition(position.x, position.y);
            textList.push_back(letter);
        } else {
            sf::Glyph g = textList.back().getFont()->getGlyph(textList.back().getString()[0],
                                                              textList.back().getCharacterSize(), true);

            Letter letter(text);
            letter.setPosition(textList.back().getPosition().x + g.advance, textList.back().getPosition().y);
            textList.push_back(letter);
        }
    }

    if(text == ' ' || text == '\n' || text == '\t' || text == '\0')
        History::push(getSnapshot(), this);

}

void DropdownList::push(const std::string& text){
    for (char x : text){
        push(x);
    }
}

void DropdownList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    //Glyph, advance
    for (auto w = textList.begin(); w != textList.end(); ++w) {
        window.draw(*w);
    }
}

void DropdownList::clear() {
    textList.clear();
}

DropdownList::iterator DropdownList::begin() {
    return textList.begin();
}

DropdownList::iterator DropdownList::end() {
    return textList.end();
}

void DropdownList::eventHandler(sf::RenderWindow &window, sf::Event event) {
    History::addEventHandler(window, event);
//    if(KeyboardShortcut::isUndo() && !History::isEmpty()) {
//        std::cout << "Undo DropdownList, applying" << History::topHistory().snapshot.getString() << std::endl;
//        applySnapshot(History::topHistory().snapshot);
//        History::popHistory();
//    }

    if (event.type == sf::Event::TextEntered){
        char input = static_cast<char>(event.text.unicode);

        if(input == 8) {
            if (textList.size() > 0)
                textList.pop_back();
        }
        else if(event.text.unicode < 128)  // Handle regular ASCII characters
            push(input);

    }
}

void DropdownList::update() {
    std::string target = "";

}

Snapshot &DropdownList::getSnapshot() {
    std::string text = "";
    for (auto w = textList.begin(); w != textList.end(); ++w)
        text += w->getString();

    Snapshot snapshot(text);
    return snapshot;
}

void DropdownList::applySnapshot(const Snapshot &snapshot) {

//    Clear the text to replace with a new one
    clear();
    push(snapshot.getString());
}

sf::Vector2f DropdownList::getPosition() {
    return textList.back().getPosition();
}

sf::Vector2f DropdownList::getPosition() const{
    return textList.back().getPosition();
}

bool DropdownList::empty() {
    return textList.empty();
}

void DropdownList::setLineHeight(const int height) {
    lineHeight = height;
}

bool DropdownList::blankLetter() {
    if(empty())
        return false;

    return textList.end()->getString() == '\0' || textList.end()->getString() == '\n' || textList.end()->getString() == '\t';
}