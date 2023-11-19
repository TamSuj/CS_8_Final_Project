//
// Created by Tammy S on 11/17/23.
//

#ifndef SFML_TEMPLATE_NODE_CPP
#define SFML_TEMPLATE_NODE_CPP

#include "Node.h"

template<typename T>
Node<T>::Node(T data) {
    this->data = data;
}

#endif //SFML_TEMPLATE_NODE_CPP