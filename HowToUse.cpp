//
// Created by Tammy S on 11/13/23.
//

#include "HowToUse.h"

HowToUse::HowToUse(sf::Vector2f position) {
    box = Box("Program Manual", size);
    box.setPosition(position);
    box.setFillColor(sf::Color::White);
    box.setOutlineColor(sf::Color(181, 181, 181));
    box.setOutlineThickness(2);

//    Title
    box.setTextPosition(sf::Vector2f(position.x + 52, position.y + 15));

//    Content (Instruction)
    for (int i = 0; i < content.size(); ++i) {
        Label label(content[i], {position.x + 20, position.y + 80 + (lineHeight * i)});
        text.push_back(label);
    }



}

void HowToUse::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void HowToUse::update() {

}

void HowToUse::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);

    for(auto w : text)
        window.draw(w);
}

Snapshot HowToUse::getSnapshot() {
    auto something = Snapshot();
    return something;
}

void HowToUse::applySnapshot(const Snapshot &snapshot) {

}
