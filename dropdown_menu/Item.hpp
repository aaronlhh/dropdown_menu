//
//  Item.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#ifndef Item_hpp
#define Item_hpp

#include <iostream>
#include "MouseEvents.hpp"
#include "States.hpp"
using namespace std;


class Item: public sf::Drawable, public sf::Transformable{
public:
    Item(string msg, sf::Vector2f vec);
    Item(string msg);
    Item();
    void setText(string msg);
    sf::FloatRect getLocalBounds();
    void setSize(float x, float y);
    void setPosition(float x, float y);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setFillColor(sf::Color color);
    string getText() const;
    bool operator==(const Item& other);
//    void setFont(sf::Font font);
//    sf::FloatRect getBounds();
    
private:
    sf::Font font;
    sf::Text text;
    sf::RectangleShape box;
    
};

#endif /* Item_hpp */
