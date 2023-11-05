//
// Created by Tammy S on 10/31/23.
//

#include "States.h"

States::States() {
    for (int i = 0; i < LAST_STATE; ++i)
        states[static_cast<statesEnum>(i)] = false;
}

void States::enableState(statesEnum state) {
    states[state] = true;
}

void States::disableState(statesEnum state) {
    states[state] = false;
}

void States::toggleState(statesEnum state) {
    states[state] = !states[state];
}

bool States::checkState(statesEnum state) const{
    return states.at(state);
}
