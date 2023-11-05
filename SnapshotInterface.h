//
// Created by Tammy S on 11/2/23.
//

#ifndef SFML_TEMPLATE_SNAPSHOTINTERFACE_H
#define SFML_TEMPLATE_SNAPSHOTINTERFACE_H

#include "Snapshot.h"
//#include "History.h"

class SnapshotInterface {
public:
    SnapshotInterface();
    // this function will return a snapshot of the object's current state
    virtual Snapshot& getSnapshot() = 0;

    // this function will apply a snapshot to the object.
    //This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //SFML_TEMPLATE_SNAPSHOTINTERFACE_H
