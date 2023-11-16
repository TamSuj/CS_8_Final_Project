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
    Snapshot(const std::string& message);
    std::string getString() const;
    void setString(std::string message);
};


#endif //SFML_TEMPLATE_SNAPSHOT_H
