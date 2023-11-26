
//
// Created by Tammy S on 11/20/23.
//

#include "NaryTree.h"

void NaryTree::push(treeNode *parent, treeNode *child) {
    if(parent && child)
        parent->children.insert(child);

}

void NaryTree::print(treeNode *node) {
//Preorder recursive function

    if(node){
        std::cout << node->data << "/";

        for(auto iter = node->children.begin(); iter != node->children.end(); ++iter)
            print(*iter);
    }
}

void NaryTree::print(treeNode *node, int depth) {
//Preorder recursive function

    if(node){
        for(int i = 0; i < depth; i++)
            std::cout << "   ";

        std::cout << (node->isFile ? "\U0001F4CE" : "\U0001F4C1") << node->data << std::endl;

        for(auto iter = node->children.begin(); iter != node->children.end(); ++iter)
            print(*iter, depth+1);

    }
}

void NaryTree::push(const std::string &path) {
//    std::string str = path;
////    Parse the string into a vector of strings which is splitted by '/'
//std::queue<std::string> components;
//std::vector<int> locations;
//
//while(str.find('/') != std::string::npos) {
//    int pos = str.find('/');
//    locations.push_back(pos);
//    str[pos] = '!';
//
//    std::string temp = "";
//    for (int i = pos-1; i >= 0; --i) {
//        if(str[i] == '/' || str[i] == '!')
//            break;
//
//        temp = path[i]+ temp;
//
//    }
//    components.push(temp);
//}
//
//components.push(str.substr(locations[locations.size()-1]+1));

std::string str = path;
std::vector<std::string> components;

// Get all the keyword in the directory
while(str.find('/') != std::string::npos) {
    int pos = str.find('/');
    components.push_back(str.substr(0, pos));
    str = str.substr(pos+1);
}
components.push_back(str);

//        Validate file path. If the first part of the directory is not the root, let user know that the path is invalid
    if (root && !components.empty() && components.front() != root->data) {
        std::cout << "Invalid directory" << std::endl;
        return;
    }

//    Start pushing stuff
for(int i = 0; i < components.size(); i++) {
    std::string name = components[i];

    if (!root) {
        treeNode *n = new treeNode;
        n->data = name;
        root = n;

    } else {
        //If root already exists, check if name is already in the tree, if not, create a new node
        treeNode *found = find(root, name);

        /*
         * pos != nullptr means name is already in the tree
         * pos == nullptr means name is NOT already in the tree
         */

//      If not found
        if(found == nullptr){
            treeNode *n = new treeNode;
            n->data = name;

            if(root->children.empty())
                push(root, n);
            else {
                treeNode *parent = find(root, components[i - 1]);
                push(parent, n);
            }
        }

        // If found, move on

    }
}
}

void NaryTree::printPath() {
    print(root);
}

void NaryTree::printTree() {
    print(root, 0);
}

treeNode* NaryTree::find(treeNode *parent, const std::string &data) {
    if(parent){
        for(auto x : parent->children){
            if(x->data == data)
                return x;
        }
    }

    return nullptr;
}

void NaryTree::fakeNaryTree() {
    auto *files = new treeNode;
    files->data = "Files";

    auto *doc = new treeNode;
    doc->data = "Documents";

//    auto *download = new treeNode;
//    download->data = "Download";
//
//    auto *desktop = new treeNode;
//    download->data = "Desktop";

    auto *project1 = new treeNode;
    project1->data = "Project_1";
    project1->isFile = true;
    auto *project2 = new treeNode;
    project2->data = "Project_2";
    project2->isFile = true;
    auto *project3 = new treeNode;
    project3->data = "Project_3";
    project3->isFile = true;

    root = files;
    push(files, doc);
//    push(files, download);
//    push(files, desktop);

    push(doc, project1);
    push(doc, project2);
    push(doc, project3);
}
