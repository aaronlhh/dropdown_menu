//
//  States.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#ifndef States_hpp
#define States_hpp

#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

class States{
public:
    enum ObjectState{
        APPEAR, CLICKED, LASTSTATE
    };
    States();
    void operator=(const States& other);
    static bool isStateEnabled(ObjectState state);
    static void setStateEnable(ObjectState state, bool set);
    static sf::Font font;
    static bool loadFont;
    
private:
    static std::map<ObjectState, bool> states;
    
    
    
};


#endif /* States_hpp */
