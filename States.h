//
// Created by Tammy S on 10/31/23.
//

#ifndef SFML_TEMPLATE_STATES_H
#define SFML_TEMPLATE_STATES_H

#include <map>
#include "StatesEnum.h"

class States {
    std::map<statesEnum, bool> states; //std::map<datatype of key (index), datatype of val>

public:
    States();
    bool checkState(statesEnum state) const; //Check the state of the object
    void enableState(statesEnum state); //Make the bool true
    void disableState(statesEnum state); //Make the bool false
    void toggleState(statesEnum state); //Switch the state to another state (true -> false)
};


#endif //SFML_TEMPLATE_STATES_H
