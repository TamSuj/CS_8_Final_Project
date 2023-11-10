//
// Created by Tammy S on 11/9/23.
//

#include "FailedList.h"

//dropdown.setSize({size.x, size.y * 2});
FailedList::FailedList() : FailedList({"Header", "subset 1", "subset 2" , "subset 3"}, {100, 100}, {0, 0}) { }

FailedList::FailedList(const std::string &message) {
    lists.push_back(message);
}

FailedList::FailedList(const std::vector<std::string> &messageVec, sf::Vector2f pos, sf::Vector2f size) {
    for (auto w = messageVec.begin(); w != messageVec.end(); ++w)
        lists.push_back(*w);

    setPosition(pos);
    header.setPosition(pos);
    header.setSize(size);
    header.setFillColor(LIGHT_BLUE);

    highlight.setFillColor(sf::Color::Transparent);
    highlight.setOutlineThickness(3);
    highlight.setOutlineColor(sf::Color::Red);
    highlight.setSize({position.x, position.y + lineHeight});
}

void FailedList::setPosition(sf::Vector2f pos) {
    position = pos;
    header.setPosition(pos);
}

void FailedList::push(const std::string& text){
    lists.push_back(text);

}

void FailedList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(header);
    Box head(lists.front(), {position.x, position.y});
    head.setPosition({position.x + MARGIN_LEFT , position.y + MARGIN_TOP});
    head.setFillColor(sf::Color::Transparent);

    window.draw(head);

    if (checkState(CLICKED)){
        Box bg({header.getSize().x, header.getPosition().y + lineHeight * (lists.size()-1)});
        bg.setPosition({position.x, header.getPosition().y + lineHeight + 2});

        if(bg.getSize().y > lists.size() * lineHeight)
            bg.setSize({bg.getSize().x, static_cast<float>((lists.size()-1) * (lineHeight) + MARGIN_TOP)});

        window.draw(bg);

        for (auto w = lists.begin(); w != lists.end(); ++w) {
            Box dropdown(*w, {position.x, position.y + lineHeight * (w - lists.begin())});
            dropdown.setText(*w);
            dropdown.setPosition(
                    {position.x + MARGIN_LEFT, position.y + lineHeight * (w - lists.begin()) + MARGIN_TOP});
            dropdown.setFillColor(sf::Color::Transparent);

            window.draw(dropdown);

//            if (w != lists.begin()) {
//                auto linePosY = dropdown.getPosition().y - lineHeight;
//                sf::Vertex lines[2];
//                lines[0] = sf::Vertex(sf::Vector2f(header.getPosition().x, linePosY), sf::Color(191, 191, 191));
//                lines[1] = sf::Vertex(sf::Vector2f(header.getSize().x, linePosY),
//                                      sf::Color(191, 191, 191)); // Additional vertex if needed
//
//                window.draw(lines, 2, sf::LineStrip); // Draw the vertex array}
//
//            }
        }

    }

//    if(checkState(HOVERED))
//        window.draw(highlight);



}

void FailedList::clear() {
    textList.clear();
}

void FailedList::eventHandler(sf::RenderWindow &window, sf::Event event) {
    History::addEventHandler(window, event);

    // Get the mouse position in window coordinates
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if(highlight.box.getGlobalBounds().contains({static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)}))
        enableState(HOVERED);
    else
        disableState(HOVERED);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {


        if(header.getPosition().x <= mousePos.x && mousePos.x <= header.getPosition().x + header.getSize().x &&
           header.getPosition().y <= mousePos.y && mousePos.y <= header.getPosition().y + header.getSize().y)
            toggleState(CLICKED);



        //    Check if user click on the menu (options)
        if(checkState(CLICKED)){
            if(header.getPosition().x <= mousePos.x && mousePos.x <= header.getPosition().x + header.getSize().x && mousePos.y >= header.getPosition().y){
//                std::cout << "mousePos: " << mousePos.y << " vs header.pos.y: " << header.getPosition().y << std::endl;
                int index = (mousePos.y - header.getPosition().y) / lineHeight;
                std::string word = lists[index];

                if(index != 0)
                    highlightText = word;

                if(changeWhenClicked && index != 0) {
                    setHeader(word);
                    toggleState(CLICKED);
                }
            }

        }
    }



    if(KeyboardShortcut::isZoomIn()){
        header.getText().setFontSize(header.getText().getFontSize() + 2);

    }else if(KeyboardShortcut::isZoomOut()){
        header.getText().setFontSize(header.getText().getFontSize() - 2);
    }

}

void FailedList::update() {
//    header.setText(lists.front());
    header.getText().setPosition({header.getText().getPosition().x + MARGIN_LEFT, header.getText().getPosition().y + MARGIN_TOP});
//    Helper<Box>::centerText(header, header.getText().getTextObj());

    menuArea = {header.getSize().x, header.getPosition().y + lineHeight * (lists.size()-1)};

    highlight.setPosition({header.getPosition().x, header.getPosition().y + lineHeight});
    highlight.setText(highlightText);
}

Snapshot &FailedList::getSnapshot() {
    std::string text = "";
    for (auto w = textList.begin(); w != textList.end(); ++w)
        text += w->getString();

    Snapshot snapshot(text);
    return snapshot;
}

void FailedList::applySnapshot(const Snapshot &snapshot) {

//    Clear the text to replace with a new one
    clear();
    push(snapshot.getString());
}

sf::Vector2f FailedList::getPosition() {
    return header.getPosition();
}

sf::Vector2f FailedList::getPosition() const{
    return getPosition();
}

bool FailedList::empty() {
    return lists.empty();
}

void FailedList::setLineHeight(const int height) {
    lineHeight = height;
}

void FailedList::setHeader(const std::string &message) {
    lists.front() = message;
}

sf::Vector2f FailedList::getSize() {
    return header.getSize();
}

void FailedList::setColor(sf::Color color) {
    header.setFillColor(color);
}

void FailedList::disableChangeWhenClicked() {
    changeWhenClicked = false;
}

void FailedList::setFontColor(const sf::Color color) {
    header.getText().setColor(color);
}
