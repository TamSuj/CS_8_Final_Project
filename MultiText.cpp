//
// Created by Tammy S on 10/17/23.
//

#include "MultiText.h"

MultiText::MultiText() : MultiText("") { }

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

//    if(text == ' ' || text == '\n' || text == '\t' || text == '\0')
//        History::push(getSnapshot(), this);

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
        else if(event.text.unicode < 128)  // Handle regular ASCII characters
            push(input);

    }

    if(KeyboardShortcut::isZoomIn()){
        for(auto w = textList.begin(); w != textList.end(); ++w){
            w->setCharacterSize(w->getCharacterSize() + 2);
            //Set the space between each character properly or else it will be crowded together
            w->setPosition(w->getPosition().x + 4, w->getPosition().y);

        }
    }
    else if(KeyboardShortcut::isZoomOut()){
        for(auto w = textList.begin(); w != textList.end(); ++w){
            w->setCharacterSize(w->getCharacterSize() - 2);
            w->setPosition(w->getPosition().x - 2, w->getPosition().y);
        }
    }
}

void MultiText::update() {
    std::string target = "";

//    Highlight reserved words
    for (auto w = textList.begin(); w != textList.end(); w++) {
        if(w->getString() != ' ' && w->getString() != '\n' && w->getString() != '\t' && w->getString() != '\0') {

            target += w->getString();

            for (const auto str: reservedWords) {
                if (str == target) {

                    int count = 0;

                    for(auto i = w; i != textList.begin(); i--) {
                        i->setFillColor(KEYWORD_COLOR);
                        count++;

                        if(count == str.length()) break;
                    }
                    break; // Exit the loop early if found
                }
            }
        }
        else
            target = "";
    }
}

Snapshot MultiText::getSnapshot() {
    std::string text = "";

    for (auto w = textList.begin(); w != textList.end(); w++) {
//        if(w->getString() != '\0' && w->getString() != '\n' && w->getString() != '\t')
            text += w->getString();
//        text += w->getChar();
    }

    std::cout << "MultiText snapshot: " << text << std::endl;
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

bool MultiText::blankLetter() {
    if(empty())
        return false;

    return textList.end()->getString() == '\0' || textList.end()->getString() == '\n' || textList.end()->getString() == '\t';
}

std::string MultiText::getString() {
    std::string str = "";

    for(auto x : textList)
        str += x.getString();

    return str;
}

void MultiText::setString(const std::string &string) {
    clear();
    push(string);
}

void MultiText::setFont(fontEnum font) {
    for (auto w = textList.begin(); w != textList.end(); w++) {
        w->setFont(Font::getFont(font));
    }


}

void MultiText::setFontSize(int size) {
    for (auto w = textList.begin(); w != textList.end(); w++)
        w->setCharacterSize(size);
}

void MultiText::setFontColor(sf::Color color) {
    for (auto w = textList.begin(); w != textList.end(); w++)
        w->setFillColor(color);

}
