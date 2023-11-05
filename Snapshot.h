//
// Created by Tammy S on 11/2/23.
//

#ifndef SFML_TEMPLATE_SNAPSHOT_H
#define SFML_TEMPLATE_SNAPSHOT_H

#include <stack>
#include <string>

class Snapshot {
    std::string snapshot;
public:
    Snapshot();
    Snapshot(std::string message);
    std::string getString() const;
};


#endif //SFML_TEMPLATE_SNAPSHOT_H
