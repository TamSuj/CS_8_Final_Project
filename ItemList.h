//
// Created by Tammy S on 11/10/23.
//

#ifndef SFML_TEMPLATE_ITEMLIST_H
#define SFML_TEMPLATE_ITEMLIST_H

#include "Item.h"
#include <vector>

class ItemList {
public:
    std::vector<Item*> items;
    void push(Item* item);
};


#endif //SFML_TEMPLATE_ITEMLIST_H
