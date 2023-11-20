
//
// Created by Tammy S on 11/20/23.
//

#include "NaryTree.h"

void NaryTree::push(treeNode *parent, treeNode *child) {

}

void NaryTree::print(treeNode *node) {
//Preorder recursive function

    if(node){
        std::cout << node->data << "/" << std::endl;

        std::set<treeNode*>::iterator iter = node->children.begin();

        for(; iter != node->children.end(); ++iter){
            print(*iter);
        }
    }
}

void NaryTree::push(const std::string &path) {
    if(!root) {
        root = new treeNode;
        treeNode* child = new treeNode;
        push(root, child);

    }
}

void NaryTree::print() {
    print(root);
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
