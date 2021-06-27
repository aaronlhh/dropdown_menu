//
//  DropdownMenu.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#ifndef DropdownMenu_hpp
#define DropdownMenu_hpp

#include "ItemList.hpp"
#include "InputBox.hpp"
#include "GUIComponent.hpp"
#include "History.hpp"

class DropdownMenu: public GUIComponent{
public:
    
    DropdownMenu();
    DropdownMenu(vector<string> vec);  // given list of string
    void resize(float x, float y);
    void setPosition(float x, float y);
    void add(string item);
    void remove(string item);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    sf::Vector2f getPosition();
    sf::FloatRect getLocalBounds();
    Snapshot& getSnapshot();
    void applySnapshot(const Snapshot& snapshot);
    
    
private:
    Snapshot snap;
    InputBox box;
    ItemList menu;
    float x, y;  // record the position
};

#endif /* DropdownMenu_hpp */
