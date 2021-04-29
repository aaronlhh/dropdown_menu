//
//  History.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#ifndef History_hpp
#define History_hpp
#include <map>
#include "stack.h"
#include "GUIComponent.hpp"

class History{

private:
    static Stack<Snapshot> stack;
public:
    static void pushHistory(const Snapshot& snapshot);
    static Snapshot topHistory();
    static void popHistory();
//    static void addEventHandler(sf::RenderWindow& window, sf::Event event);

};

#endif /* History_hpp */

