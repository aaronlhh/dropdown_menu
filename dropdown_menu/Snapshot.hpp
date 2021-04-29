//
//  Snapshot.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#ifndef Snapshot_hpp
#define Snapshot_hpp
#include <iostream>

class Snapshot{
public:
    Snapshot(std::string data = "");
    std::string getData() const;
    void setString(std::string other);
    
private:
    std::string data;
};

#endif /* Snapshot_hpp */
