//
// Created by Tammy S on 11/16/23.
//
#ifndef SFML_TEMPLATE_FILETREE_CPP
#define SFML_TEMPLATE_FILETREE_CPP

#include "FileTree.h"

template<typename T>
FileTree<T>::FileTree() {
    init();

}

template<typename T>
FileTree<T>::FileTree(const T &item, bool isFileNode) : name(item), isFile(isFileNode) {
    init();
//    std::cout << "FileTree() is called" << std::endl;

//    if (!folderTexture.loadFromFile("Materials/icon.png") || !fileTexture.loadFromFile("Materials/file.png"))
//        std::cout << "Error loading image" << std::endl; // Handle loading error
//
//    folder = sf::Sprite(folderTexture); // Create a sprite
//    file = sf::Sprite(fileTexture); // Create a sprite
//
//    // Set the size of the sprite (optional)
//    folder.setScale(0.5f, 0.5f); // Set scale factors for width and height
//    file.setScale(0.5f, 0.5f); // Set scale factors for width and height

//    // Set the position of the sprite
//    file.setPosition(300, 150);
//    folder.setPosition(400, 250);
}

template<typename T>
void FileTree<T>::addNode(FileTree *node) {
    children.push_back(node);

}

template<typename T>
void FileTree<T>::printTree(FileTree<T> *node, int depth) {
//Only print if root is not nullptr
    if (node != nullptr) {

        // Print the current node (directory or file)
        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";  // Adjust indentation for better visualization
        }

        std::cout << (node->isFile ? "\U0001F4CE " : "\U0001F4C1 ") << node->name << std::endl;

        sf::Vector2f start = {0, 0};
        std::string name = static_cast<std::string>(node->name);
//        name = (node->isFile ? "" : "> ") + name;
        name = "     " + name;
        MenuBar* temp = new MenuBar(name, {0,0}, {150, 50});
//        temp->setColor(sf::Color(252, 186, 3));
        temp->setPosition({static_cast<float>(depth * 40), static_cast<float>(start.y + (depth * margin))});
        temp->setHeader(name);
        temp->setSize({(name.size() * 2) + 170.0f, 50});

        //Issue right now is that all the file or folder in the same level are overlapped each other, find the way to
//        separate them and make sure the position.x is correct
        dropdowns.push_back(temp);

        // Recursively print children
        for (FileTree<T> *child: node->children) {
            printTree(child, depth + 1);
        }

    }

//    Set all the dropdowns to hidden state (when first created
    for(int i = 1; i < dropdowns.size(); ++i) {
        dropdowns[i]->enableState(HIDDEN);
    }
}

template<typename T>
void FileTree<T>::fakeTree() {
    // Creating a file system tree of strings
    auto* root = new FileTree<std::string>("Files", false);

    // Adding directories and files
    auto* desktop = new FileTree<std::string>("Desktop", false);
    auto* downloads = new FileTree<std::string>("Downloads", false);
    auto* file0 = new FileTree<std::string>("file0.jpg", true);
    auto* file1 = new FileTree<std::string>("file1.txt", true);
    auto* file2 = new FileTree<std::string>("file2.jpg", true);

    auto* subFolder1 = new FileTree<std::string>("Submission", false);
    auto* subFile1 = new FileTree<std::string>("HW1.png", true);
    auto* subFile2 = new FileTree<std::string>("HW2.png", true);

    auto* subFolder2 = new FileTree<std::string>("Note", false);
    auto* note1 = new FileTree<std::string>("Chemistry.txt", true);
    auto* note2 = new FileTree<std::string>("Physics.txt", true);

    root->addNode(desktop);
    root->addNode(downloads);
    downloads->addNode(file0);
    downloads->addNode(file1);
    downloads->addNode(file2);
    desktop->addNode(subFolder1);

    subFolder1->addNode(subFile1);
    subFolder1->addNode(subFile2);
    subFolder1->addNode(subFolder2);

    subFolder2->addNode(note1);
    subFolder2->addNode(note2);

    // Print the file tree
    printTree(root);
}

template<typename T>
void FileTree<T>::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    int i = 0;

    //Only draw if the header is clicked
    if(CLICKED){
            for (auto x: dropdowns) {
                if (!x->checkState(HIDDEN)) {

                    sf::RectangleShape bg;
                    bg.setPosition({0, x->getPosition().y});
//            bg.setSize(x->getSize());
                    if (i != 0)
                        bg.setSize({SCREEN_WIDTH / 2, x->getSize().y});
                    bg.setFillColor(fileBGColor);
                    window.draw(bg);

                    window.draw(*x);

//            window.draw(file);
//            window.draw(folder);

//            if(!isFile)
//                window.draw(folder);
//            else
//                window.draw(file);
                    i++;
                }
            }
        }
}

template<typename T>
void FileTree<T>::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    mpos.y -= margin;

    if(mpos.x >= dropdowns[0]->getPosition().x && mpos.x <= dropdowns[0]->getSize().x + dropdowns[0]->getPosition().x &&
       mpos.y <= dropdowns[0]->getPosition().y && mpos.y >= dropdowns[0]->getPosition().y - dropdowns[0]->getSize().y && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        toggleState(CLICKED);

    if(checkState(CLICKED)) {
        for (auto i: dropdowns) {

            //            std::cout << i->getHeader() << " pos: (" << i->getPosition().x << ", " << i->getPosition().y << ") -> (" << i->getSize().x << ", " << i->getSize().y << ")"<<  std::endl;

            if (mpos.x >= i->getPosition().x && mpos.x <= i->getSize().x + i->getPosition().x &&
                mpos.y <= i->getPosition().y && mpos.y >= i->getPosition().y - i->getSize().y) {
                i->setColor(highlightColor);

                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    //Toggle HIDDEN state all the dropdowns that is the children of the node that is clicked
                    for (auto x: dropdowns) {
                        if (x->getPosition().y > i->getPosition().y && x->getPosition().x > i->getPosition().x) {
                            x->toggleState(HIDDEN);
                        }
                    }
                }

            } else
                i->setColor(fileBGColor);
        }
    }



}

template<typename T>
void FileTree<T>::update() {
    // REMOVE_ME REMOVE ME
//    bool fix = false;
//    auto fixMe = dropdowns[0];
//
//    for (int i = 0; i < dropdowns.size(); ++i) {
//        auto current = dropdowns[i];
//
////        Check if there any MenuBar* that has the same position. If yes, set fix = true
//        for(auto x : dropdowns) {
//            if(x != current && (x->getPosition() == current->getPosition() || x->getPosition().y == current->getPosition().y)) {
//                fix = true;
//                fixMe = x;
//                break;
//            }
//        }
//
//        if(fix){
//            fixMe->setPosition({fixMe->getPosition().x, fixMe->getPosition().y + margin});
//            fix = false;
//        }
//    }
    // remove_me remove me remove

    if(!dropdowns.size() == 0)
        header = dropdowns[0];

    for (int i = 0; i < dropdowns.size(); ++i) {
        auto current = dropdowns[i];

        // Check if there are any MenuBar* that have the same position or y-coordinate
        for (auto x : dropdowns) {
            if (x != current && (x->getPosition() == current->getPosition() || x->getPosition().y == current->getPosition().y)) {
                // Adjust the position of all overlapping MenuBar elements
                x->setPosition({x->getPosition().x, x->getPosition().y + margin});
            }
        }
    }

//    Rearrange the order of the menuBar after toggle state of some menu bar to hidden
    for (int i = 0; i < dropdowns.size(); ++i) {
        if(dropdowns[i]->checkState(HIDDEN)) {

            for (int j = i+1; j < dropdowns.size(); ++j) {
                if(!dropdowns[j]->checkState(HIDDEN)) {
                    dropdowns[j]->setPosition({dropdowns[j]->getPosition().x, dropdowns[j]->getPosition().y - margin});
                    file.setPosition(dropdowns[j]->getPosition());
                    folder.setPosition(dropdowns[j]->getPosition());
                }

            }
        }
    }
}

template<typename T>
Snapshot FileTree<T>::getSnapshot() {
    return Snapshot();
}

template<typename T>
void FileTree<T>::applySnapshot(const Snapshot &snapshot) {

}

template<typename T>
void FileTree<T>::init() {
//    if (!folderTexture.loadFromFile("Materials/icon.png") || !fileTexture.loadFromFile("Materials/file.png"))
//        std::cout << "Error loading image" << std::endl; // Handle loading error
//
//    folder = sf::Sprite(folderTexture); // Create a sprite
//    file = sf::Sprite(fileTexture); // Create a sprite
//
//    // Set the size of the sprite (optional)
//    folder.setScale(0.05f, 0.05f); // Set scale factors for width and height
//    file.setScale(0.05f, 0.05f); // Set scale factors for width and height
//
//    // Set the position of the sprite
//    file.setPosition(12, 10);
//    folder.setPosition(60, 60);
}

template<typename T>
void FileTree<T>::setHeaderColor(sf::Color color) {
    if(header)
        header->setColor(color);
}

#endif