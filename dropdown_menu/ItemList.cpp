//
//  ItemList.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#include "ItemList.hpp"

ItemList::ItemList(){
//    font.loadFromFile("OpenSans-Bold.ttf");
//    add("Something");
}


ItemList::ItemList(vector<string> vec){
//    Item a(vec.at(0));
//    itemlist.insert_head(a);
//    for(int i = 1; i < vec.size(); ++i){
//        Item temp(vec.at(i));
//        float x = itemlist[i-1].getLocalBounds().left;
//        float y = itemlist[i-1].getLocalBounds().top + itemlist[i-1].getLocalBounds().height;
//        temp.setPosition(x, y);
//        itemlist.insert_back(temp);
//    }
//    font.loadFromFile("OpenSans-Bold.ttf");
    for(int i = 0; i < vec.size(); ++i){
        add(vec.at(i));
    }
    word = "";
}

void ItemList::setPosition(float x, float y){
    int index = 0;
    for(list<Item>::Iterator i = itemlist.begin(); i != itemlist.end(); ++i){
        i->setPosition(x, y + index * i->getLocalBounds().height);
        ++index;
    }
}


void ItemList::setSize(float x, float y){
    for(list<Item>::Iterator i = itemlist.begin(); i != itemlist.end(); ++i){
        i->setSize(x, y);
    }
    
    // reset position of each item
//    float xPos = itemlist.begin()->getLocalBounds().left;
//    float yPos = itemlist.begin()->getLocalBounds().top;
//    int index = 0;
//    for(list<Item>::Iterator j = itemlist.begin(); j != itemlist.end(); ++j){
//        j->setPosition(xPos, yPos + index * j->getLocalBounds().height);
//        ++index;
//    }
    setPosition(getPosition().x, getPosition().y);
    
}


void ItemList::add(string item){
    if(itemlist.begin().is_null()){
        Item temp(item);
        itemlist.insert_head(temp);
        setPosition(getPosition().x, getPosition().y);
        return;
    }
    
    sf::FloatRect dimension = itemlist.begin()->getLocalBounds();
    Item temp(item);
    temp.setSize(dimension.width, dimension.height);
    itemlist.insert_back(temp);
    setPosition(getPosition().x, getPosition().y);
}


void ItemList::remove(string item){
    for(list<Item>::Iterator j = itemlist.begin(); j != itemlist.end(); ++j){
        if(j->getText() == item){
            itemlist.delete_node(j);
            break;
        }
    }
    setPosition(getPosition().x, getPosition().y);
}

sf::FloatRect ItemList::getLocalBounds() const{
    sf::FloatRect rec = itemlist.begin()->getLocalBounds();
    int count = 0;
    for(list<Item>::Iterator i = itemlist.begin(); i < itemlist.end(); ++i){
        count++;
    }
    rec.height *= count;
    return rec;
}


void ItemList::addEventHandler(sf::RenderWindow& window, sf::Event event){
    for(list<Item>::Iterator i = itemlist.begin(); i != itemlist.end(); ++i){
        if(MouseEvents<Item>::hovered(*i, window)){
            i->setFillColor(sf::Color::Blue);
        }else{
            i->setFillColor(sf::Color::Transparent);
        }
        
        if(MouseEvents<Item>::mouseClicked(*i, window)){
            // if mouse clicked on an option, closed the bar
            // set clicked state to be true
            States::setStateEnable(States::APPEAR, false);
            States::setStateEnable(States::CLICKED, true);
            word = i->getText();
        }
    }
}

string ItemList::getClicked(){
    return word;
}


void ItemList::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    if(itemlist.begin().is_null())
        return;
    for(list<Item>::Iterator i = itemlist.begin(); i != itemlist.end(); ++i){
        window.draw(*i);
    }
}
