//
//  SnapshotInterface.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#ifndef SnapshotInterface_hpp
#define SnapshotInterface_hpp
#include "Snapshot.hpp"

class SnapshotInterface{
public:
    // this function will return a snapshot of the object's current state
    virtual Snapshot& getSnapshot() = 0;
    
    // this function will apply a snapshot to the object.
    // This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};

#endif /* SnapshotInterface_hpp */
