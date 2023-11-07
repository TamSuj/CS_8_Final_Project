//
// Created by Tammy S on 10/18/23.
//

#include "Application.h"


std::vector<GUIComponent*> Application::components;

Application::Application() { }

void Application::addComponent(GUIComponent &component) {
    components.push_back(&component);
}

void Application::run() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), PROJECT_NAME);
    window.setFramerateLimit(60);
//    std::string filename = "Output";
//    filename += ".png";
//    Box box;
//    Application::addComponent(box);

    TextInput textInput1({250, 100} , {200, 50});
    TextInput textInput2({250, 200}, {300, 50});
    TextInput textInput3({250, 300}, {300, 50});
    TextInput textBox({100, 450}, {600, 150});
    Label label1("Date:", {100, 110});
    Label label2("Name:", {100, 210});
    Label label3("Age:", {100, 310});
    Label label4("Note:", {100, 410});

    Application::addComponent(textInput1);
    Application::addComponent(textInput2);
    Application::addComponent(textInput3);
    Application::addComponent(textBox);

    Application::addComponent(label1);
    Application::addComponent(label2);
    Application::addComponent(label3);
    Application::addComponent(label4);

//    if(MouseEvents<TextInput>::mouseClicked(textInput, window))
//        std::cout << "mouse clicked" << std::endl;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            for (GUIComponent* &g : components)
                g->eventHandler(window, event);

            for (GUIComponent* &g : components)
                g->update();

            EventHandler::basicEventHandler(window, event);
        }

        window.clear(BG_COLOR);

        for (GUIComponent* &g : components) {
            window.draw(*g);
        }

        window.display();
    }
}

/* Screenshot

*Modified*
sf::Texture texture;
texture.create(window.getSize().x, window.getSize().y);
texture.update(window);
if (texture.copyToImage().saveToFile(filename))
{
    std::cout << "screenshot saved to " << filename << std::endl;
}



*Original*
sf::Texture texture;
texture.create(render_window.getSize().x, render_window.getSize().y);
texture.update(render_window);
if (texture.copyToImage().saveToFile(filename))
{
std::cout << "screenshot saved to " << filename << std::endl;
}
 */