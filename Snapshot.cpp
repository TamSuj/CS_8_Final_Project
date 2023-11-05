//
// Created by Tammy S on 11/2/23.
//

#include "Snapshot.h"

Snapshot::Snapshot() { }

Snapshot::Snapshot(std::string message) : snapshot(message) { }

std::string Snapshot::getString() const {
    return snapshot;
}
