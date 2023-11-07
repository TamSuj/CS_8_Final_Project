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
    if (text == '\n') {
        // If the Enter key is pressed, move to a new line
        position.y += lineHeight; // Move to the next line

        Letter letter(text);
        letter.setPosition(position.x-DEFAULT_TEXT_SIZE+10, textList.back().getPosition().y + lineHeight);
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
    if(KeyboardShortcut::isUndo()) {
        std::cout << "Undo" << std::endl;
        applySnapshot(getSnapshot());
    }

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

void MultiText::update() {
    std::string target = "";
    bool found;

    for (auto w = textList.begin(); w != textList.end(); w++) {
        found = false;

        if(w->getString() != ' ') {
            target += w->getString();


            for (const auto str: reservedWords) {
                if (str == target) {
                    found = true;
                    break; // Exit the loop early if found
                }
            }

            if (found) {

                for(auto i = w; i != textList.begin(); i--) {
                    i->setFillColor(KEYWORD_COLOR);

                    if(i->getString() == target[0])
                        break;
                }
            }
        }
        else
            target = "";
    }
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

void MultiText::setLineHeight(const int height) {
    lineHeight = height;
}
