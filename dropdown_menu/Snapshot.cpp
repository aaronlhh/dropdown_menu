//
//  Snapshot.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#include "Snapshot.hpp"


Snapshot::Snapshot(std::string data){
    this->data = data;
}


std::string Snapshot::getData() const{
    return data;
}

void Snapshot::setString(std::string other){
    data = other;
//    std::cout << "\nSnapshot-setString(): " << other << std::endl;
}
