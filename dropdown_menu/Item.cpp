//
//  Item.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#include "Item.hpp"


Item::Item(string msg, sf::Vector2f vec){
    box.setSize(vec);
    box.setFillColor(sf::Color::Transparent);
    
    if(!States::loadFont){
        States::font.loadFromFile("OpenSans-Bold.ttf");
    }
    text.setFont(States::font);
    text.setString(msg);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(vec.y/2);
    text.setPosition(box.getPosition().x + box.getLocalBounds().width/2 - text.getLocalBounds().width/2,
                     box.getPosition().y + box.getLocalBounds().height/2 - text.getLocalBounds().height/1.5);
}


Item::Item(string msg)
: Item(msg, {500,100}){
    
}


Item::Item()
: Item("Something", {500, 100}){
    
}



void Item::setText(string msg){
    text.setString(msg);
}


sf::FloatRect Item::getLocalBounds() const{
    return box.getGlobalBounds();
}


void Item::setSize(float x, float y){
    box.setSize({x,y});
    text.setCharacterSize(y/2);
}


void Item::setPosition(float x, float y){
    box.setPosition(x, y);
    text.setPosition(x + box.getGlobalBounds().width/2 - text.getGlobalBounds().width/2,
                     y + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/1.5);
    
}


void Item::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(box);
    window.draw(text);
    
}


void Item::setFillColor(sf::Color color){
    box.setFillColor(color);
}


string Item::getText() const{
    return text.getString();
}

bool Item::operator==(const Item& other){
    return getText() == other.getText();
}


//void Item::setFont(sf::Font font){
//    text.setFont(font);
//}


//sf::FloatRect Item::getBounds(){
//    return text.getGlobalBounds();
//}
