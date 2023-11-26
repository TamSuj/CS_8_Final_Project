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
    std::vector<MenuBar*> menus;
    std::vector<TextInput*> textInputs;

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

    TextInput textInput2({250, 200}, {300, 50}); //Title
    TextInput textInput3({250, 300}, {300, 50}); //Tag
    TextInput textBox({100, 450}, {600, 250});

    textInputs.push_back(&textInput2);
    textInputs.push_back(&textInput3);
    textInputs.push_back(&textBox);

    Label dateInput("Date:", {100, 110});
    Label titleInput("Title:", {100, 210});
    Label tagInput("Tag:", {100, 310});
    Label noteInput("Note:", {100, 410});

//    MenuBar dropdownList1({"File", "Open", "Save", "Export"}, {0, 0}, {170, 50}, sf::Color(147, 181, 198));
//    dropdownList1.setHighlightColor(sf::Color(251, 176, 45));

//    FileTree
    FileTree<std::string> ft;
    ft.fakeTree();
//    ft.setHeaderColor(sf::Color(147, 181, 198));

    MenuBar dropdownList2({"Font", "Lato", "Noto San", "Open San", "Product San", "Courier"}, {190, 0}, {150, 50}, sf::Color(221, 237, 170));
    MenuBar dropdownList3({"Font color", "Red", "Blue", "Green", "Yellow", "Orange", "Purple"}, {340, 0}, {150, 50}, sf::Color(240, 207, 101));
    MenuBar nameMenuBar({"Tags", "School", "Work", "Hobby", "Other"}, {570, 300}, {120, 50}, sf::Color(215, 129, 106));
    MenuBar menu1({"Font size", "Large", "Medium", "Small"}, {dropdownList3.getPosition().x + 150, 0}, {150, 50}, sf::Color(189, 79, 108));
    MenuBar menu2({"Other", "Close", "Manuel"}, {640, 0}, {150, 50},sf::Color(158, 197, 171));

    menus.push_back(&dropdownList2);
    menus.push_back(&dropdownList3);
    menus.push_back(&nameMenuBar);
    menus.push_back(&menu1);
    menus.push_back(&menu2);

    HowToUse help({SCREEN_WIDTH - 350, SCREEN_HEIGHT - 350});

//    fileDropdown file(ft, {0, 50}, {200, 50});

    //    Application::addComponent(textInput1);
    Application::addComponent(textInput2);
    Application::addComponent(textInput3);
    Application::addComponent(textBox);

    Application::addComponent(dateInput);
    Application::addComponent(titleInput);
    Application::addComponent(tagInput);
    Application::addComponent(noteInput);

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


    Application::addComponent(ft);

    Application::addComponent(help);


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

            for(auto x : menus){
                std::string userChoice = x->getSelectedText();
                if(userChoice != ""){
                    if(userChoice == "Close") {
                        std::cout << "Window closed" << std::endl;
                        window.close();
                    }
                    else if(userChoice == "Lato"){
                        for(auto textBox : textInputs){
                            textBox->setFont(LATO);
                        }
                    }
                    else if(userChoice == "Noto San"){
                        for(auto textBox : textInputs){
                            textBox->setFont(NOTO_SANS);
                        }
                    }else if(userChoice == "Open San"){
                        for(auto textBox : textInputs){
                            textBox->setFont(OPEN_SANS);
                        }
                    }
                    else if(userChoice == "Product San"){
                        for(auto textBox : textInputs){
                            textBox->setFont(PRODUCT_SANS);
                        }
                    }
                    else if(userChoice == "Courier"){
                        for(auto textBox : textInputs){
                            textBox->setFont(COURIER);
                        }
                    }
                    else if(userChoice == "Large"){
                        for(auto textBox : textInputs){
                            textBox->setFontSize(27);
                        }
                    }
                    else if(userChoice == "Medium"){
                        for(auto textBox : textInputs){
                            textBox->setFontSize(23);
                        }
                    }
                    else if(userChoice == "Small"){
                        for(auto textBox : textInputs){
                            textBox->setFontSize(20);
                        }
                    }
                    else if(userChoice == "Manuel" && event.type == sf::Event::MouseButtonPressed){
//                        help.setClose(true);
                        help.toggleState();
                    }
                    else if(userChoice == "Red"){
                        for(auto textBox : textInputs){
                            textBox->setFontColor(sf::Color(191, 48, 72));
                        }
                    }
                    else if(userChoice == "Blue"){
                        for(auto textBox : textInputs){
                            textBox->setFontColor(sf::Color(57, 130, 198));
                        }
                    }
                    else if(userChoice == "Green"){
                        for(auto textBox : textInputs){
                            textBox->setFontColor(sf::Color(21, 163, 31));
                        }
                    }
                    else if(userChoice == "Yellow"){
                        for(auto textBox : textInputs){
                            textBox->setFontColor(sf::Color(227, 185, 0));
                        }
                    }
                    else if(userChoice == "Orange"){
                        for(auto textBox : textInputs){
                            textBox->setFontColor(sf::Color(250, 121, 0));
                        }
                    }else if(userChoice == "Purple"){
                        for(auto textBox : textInputs){
                            textBox->setFontColor(sf::Color(165, 50, 237));
                        }
                    }

                    // {"Tags", "School", "Work", "Hobby", "Other"}

                    else if(userChoice == "School" || userChoice == "Work" || userChoice == "Hobby" || userChoice == "Other"){
                        textInput3.setString(userChoice);
                    }
                }
            }
        }
        for (GUIComponent* &g : components)
            g->update();

        window.clear(BG_COLOR);
//        window.clear(sf::Color::White);
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