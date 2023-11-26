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

    closeIcon = Label("X", {box.getPosition().x + box.getSize().x - 30, box.getPosition().y + 15}, 20);

}

void HowToUse::eventHandler(sf::RenderWindow &window, sf::Event event) {
    //If mouse is clicked in the close icon area, set close = true (to not draw the box)
    auto mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    if(KeyboardShortcut::isX())
        close = true;

//    if(!close){
        if (event.type == sf::Event::MouseButtonPressed && mpos.x >= 735 && mpos.x <= 755 && mpos.y >= 415 &&
            mpos.y <= 435) {
            std::cout << "Close manuel" << std::endl;
            close = true;
        }
//    }

}

void HowToUse::update() {
}

void HowToUse::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!close) {
        window.draw(box);
        window.draw(closeIcon);

        for (auto w: text)
            window.draw(w);
    }
}

Snapshot HowToUse::getSnapshot() {
    auto something = Snapshot();
    return something;
}

void HowToUse::applySnapshot(const Snapshot &snapshot) {

}

void HowToUse::toggleState() {
    std::cout << "Toggle state: " << (close == true ? "true" : "false") << std::endl;
    close = !close;
}
