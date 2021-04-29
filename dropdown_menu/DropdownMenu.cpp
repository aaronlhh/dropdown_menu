//
//  DropdownMenu.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#include "DropdownMenu.hpp"


void DropdownMenu::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(box);
    if(States::isStateEnabled(States::APPEAR))
        window.draw(menu);
}


void DropdownMenu::addEventHandler(sf::RenderWindow& window, sf::Event event){
    // undo key
    if(
           ( sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem) )&&
           ( sf::Keyboard::isKeyPressed(sf::Keyboard::Z) )
       ){
        if(History::topHistory().getData() != ""){
            applySnapshot(History::topHistory());
            History::popHistory();
        }
    }
    
    
    if(MouseEvents<InputBox>::mouseClicked(box, window)){
        if(States::isStateEnabled(States::APPEAR))
            States::setStateEnable(States::APPEAR, false);
        else
            States::setStateEnable(States::APPEAR, true);
    }
    
    if(States::isStateEnabled(States::APPEAR)){
        menu.addEventHandler(window, event);
    }
}


void DropdownMenu::update(){
    if(States::isStateEnabled(States::CLICKED)){
        History::pushHistory(getSnapshot());
        States::setStateEnable(States::CLICKED, false);
        box.setText(menu.getClicked());
        setPosition(x, y);
    }
}


DropdownMenu::DropdownMenu()
: DropdownMenu(vector<string>{"Something"}){
    
}


DropdownMenu::DropdownMenu(vector<string> vec){
    x = 0;
    y = 0;
    box.setPosition(x, y);
    box.setText(vec.at(0));
    menu.setPosition(0, box.getLocalBounds().height + 5);
    for(int i = 0; i < vec.size(); i++){
        menu.add(vec.at(i));
    }
}


void DropdownMenu::resize(float x, float y){
    box.setSize(x, y);
    menu.setSize(x, y);
}


void DropdownMenu::setPosition(float x, float y){
    this->x = x;
    this->y = y;
    box.setPosition(x, y);
    menu.setPosition(x, y + box.getLocalBounds().height + 5);
}


void DropdownMenu::add(string item){
    menu.add(item);
}

void DropdownMenu::remove(string item){
    menu.remove(item);
}


Snapshot& DropdownMenu::getSnapshot(){
    snap.setString(box.getText());
    return snap;
}


void DropdownMenu::applySnapshot(const Snapshot& snapshot){
    string other = snapshot.getData();
    box.setText(other);
    setPosition(x, y);
}
