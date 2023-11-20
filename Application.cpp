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
    std::string filename = "Screenshot.png";
//    Box box;
//    Application::addComponent(box);

//    DropdownMenu dropdownMenu({5, 5}, {200, 50}, sf::Color::Green);

//    TextInput textInput1({250, 100} , {200, 50});
    DropdownMenus dateDropdown({"Day", "Mon", "Tues", "Wed", "Thu", "Fri", "Sat", "Sun" }, {250, 100}, {100, 50}, sf::Color(116, 211, 174));
    DropdownMenus monthDropdown({"Month", "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" }, {370, 100}, {120, 50}, sf::Color(103, 141, 88));
    DropdownMenus yearDropdown({"Year", "2020", "2021", "2022", "2023", "2024", "2025" }, {510, 100}, {100, 50}, sf::Color(166, 196, 138));

    TextInput textInput2({250, 200}, {300, 50});
    TextInput textInput3({250, 300}, {300, 50});
    TextInput textBox({100, 450}, {600, 250});
    Label label1("Date:", {100, 110});
    Label label2("Name:", {100, 210});
    Label label3("Age:", {100, 310});
    Label label4("Note:", {100, 410});

    MenuBar dropdownList1({"File", "Open", "Save", "Export"}, {0, 0}, {170, 50}, sf::Color(147, 181, 198));
    dropdownList1.setHighlightColor(sf::Color(251, 176, 45));
    MenuBar dropdownList2({"Edit", "Undo", "Redo"}, {dropdownList1.getSize().x, 0}, {150, 50}, sf::Color(221, 237, 170));
    MenuBar dropdownList3({"Format", "Font", "Font size", "Line height"}, {dropdownList2.getSize().x * 2, 0}, {150, 50}, sf::Color(240, 207, 101));

    MenuBar nameMenuBar({"Sample names", "Kelly", "Sam", "Mark", "Tim", "Matt", "James"}, {570, 200}, {200, 50}, sf::Color(215, 129, 106));

    MenuBar menu1({"Others", "choice 1", "choice 2", "choice 3", "choice 4", "choice 5", "choice 6", "choice 7"}, {dropdownList3.getPosition().x + 150, 0}, {150, 50}, sf::Color(189, 79, 108));
    MenuBar menu2({"Help", "Close", "Reload"}, {600, 0}, {150, 50},sf::Color(158, 197, 171));
    HowToUse help({SCREEN_WIDTH - 350, SCREEN_HEIGHT - 350});

//    FileTree
    FileTree<std::string> ft;
    ft.fakeTree();

//    fileDropdown file(ft, {0, 50}, {200, 50});

/*

    //    Application::addComponent(textInput1);
    Application::addComponent(textInput2);
    Application::addComponent(textInput3);
    Application::addComponent(textBox);

    Application::addComponent(label1);
    Application::addComponent(label2);
    Application::addComponent(label3);
    Application::addComponent(label4);

    Application::addComponent(nameMenuBar);
    Application::addComponent(dateDropdown);
    Application::addComponent(monthDropdown);
    Application::addComponent(yearDropdown);

//    Application::addComponent(dropdownList1);
    Application::addComponent(dropdownList2);
    Application::addComponent(dropdownList3);

    Application::addComponent(menu1);
    Application::addComponent(menu2);
//    Application::addComponent(file);

    */
    Application::addComponent(ft);

//    Application::addComponent(help);


//    Application::addComponent(dropdownMenu);

//    if(MouseEvents<TextInput>::mouseClicked(textInput, window))
//        std::cout << "mouse clicked" << std::endl;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            for (GUIComponent* &g : components)
                g->eventHandler(window, event);


            EventHandler::basicEventHandler(window, event);
            EventHandler::screenshot(window, event, filename);
            History::addEventHandler(window, event);
        }
        for (GUIComponent* &g : components)
            g->update();

//        window.clear(BG_COLOR);
        window.clear(sf::Color::White);
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