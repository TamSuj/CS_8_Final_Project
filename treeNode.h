//
// Created by Tammy S on 11/20/23.
//

#ifndef SFML_TEMPLATE_TREENODE_H
#define SFML_TEMPLATE_TREENODE_H

#include <string>
#include <set>

class treeNode {
    public:
    std::string data;
    std::set<treeNode*> children;
};


#endif //SFML_TEMPLATE_TREENODE_H
