//
//  ItemList.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#ifndef ItemList_hpp
#define ItemList_hpp
#include "Item.hpp"
#include "list.h"

class ItemList: public sf::Drawable, public sf::Transformable{
public:
    ItemList();
    ItemList(vector<string> vec);   // given a vector of string
    void setPosition(float x, float y);
    void setSize(float x, float y);   // x = width of a single Item inside list,
                                      // y = height of a single item
    void add(string item);      // add an item to the list
    void remove(string item);   // delete an item with msg == item
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    string getClicked();
    
    
    friend void operator<<(ostream& outs, const ItemList& other){
        for(list<Item>::Iterator i = other.itemlist.begin(); i != other.itemlist.end(); ++i){
            cout << i->getText() << ": ( " << i->getLocalBounds().left << ", " << i->getLocalBounds().top << ")\n";
        }
    }
    
private:
    list<Item> itemlist;
    sf::Font font;
    string word;
};


#endif /* ItemList_hpp */
