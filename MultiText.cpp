//
// Created by Tammy S on 10/17/23.
//

#include "MultiText.h"

MultiText::MultiText() : MultiText("") {

}

MultiText::MultiText(const std::string &message) {
    push(message);
}

MultiText::MultiText(const std::string &message, sf::Vector2f pos) {
    push(message);
    setPosition(pos);
}

void MultiText::setPosition(sf::Vector2f pos) {
    position = pos;
}

void MultiText::push(char text){
    if(textList.empty()) {
        Letter letter(text);
        letter.setPosition(position.x, position.y);
        textList.push_back(letter);
    }else{
        sf::Glyph g = textList.back().getFont()->getGlyph(textList.back().getString()[0], textList.back().getCharacterSize(), true);

        Letter letter(text);
        letter.setPosition(textList.back().getPosition().x + g.advance, textList.back().getPosition().y);
        textList.push_back(letter);
    }
}

void MultiText::push(const std::string& text){
    for (char x : text){
        push(x);
    }
}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    //Glyph, advance
    for (auto w = textList.begin(); w != textList.end(); ++w) {
        window.draw(*w);
    }
}

void MultiText::clear() {
    textList.clear();
}

MultiText::iterator MultiText::begin() {
    return textList.begin();
}

MultiText::iterator MultiText::end() {
    return textList.end();
}

void MultiText::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::TextEntered){
        char input = static_cast<char>(event.text.unicode);

        if(input == 8) {
            if (textList.size() > 0)
                textList.pop_back();
        }
        else if (event.text.unicode < 128) { // Handle regular ASCII characters
            push(input);
        }
    }
}

void MultiText::update() {

}

Snapshot &MultiText::getSnapshot() {
    std::string text = "";
    for (auto w = textList.begin(); w != textList.end(); ++w)
        text += w->getString();

    Snapshot snapshot(text);
    return snapshot;
}

void MultiText::applySnapshot(const Snapshot &snapshot) {

//    Clear the text to replace with a new one
    clear();
    push(snapshot.getString());
}

sf::Vector2f MultiText::getPosition() {
    return textList.back().getPosition();
}

sf::Vector2f MultiText::getPosition() const{
    return textList.back().getPosition();
}

bool MultiText::empty() {
    return textList.empty();
}
