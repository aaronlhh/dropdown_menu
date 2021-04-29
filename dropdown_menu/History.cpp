//
//  History.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#include "History.hpp"


Stack<Snapshot> History::stack;


void History::pushHistory(const Snapshot& snapshot){
    stack.push(snapshot);
}


Snapshot History::topHistory(){
    if(stack.top().is_null()){
        Snapshot temp("");
        return temp;
    }
    return *stack.top();
}


void History::popHistory(){
    stack.pop();
}


//void History::addEventHandler(sf::RenderWindow& window, sf::Event event){
//    // nothing
//}


//History::Response History::getComponent(std::string componentID){
//
//}
//
//
//void History::addComponent(std::string componentID, GUIComponent* component){
//
//}


