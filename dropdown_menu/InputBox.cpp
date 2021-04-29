//
//  InputBox.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#include "InputBox.hpp"


InputBox::InputBox(string msg, sf::Vector2f vec, sf::Color color){
    
    box.setSize(vec);
    box.setOutlineThickness(5);
    box.setOutlineColor(color);
    box.setFillColor(sf::Color::Transparent);
    
    if(!States::loadFont){
        States::font.loadFromFile("OpenSans-Bold.ttf");
    }
//    text.setFont(font);
    text.setFont(States::font);
    text.setString(msg);
    text.setFillColor(color);
    text.setCharacterSize(vec.y/2);
    text.setPosition(box.getPosition().x + box.getLocalBounds().width/2 - text.getLocalBounds().width/2,
                     box.getPosition().y + box.getLocalBounds().height/2 - text.getLocalBounds().height/1.5);
    
}


InputBox::InputBox(string msg, sf::Vector2f vec)
: InputBox(msg, vec, sf::Color::White){
    
}


InputBox::InputBox(string msg)
: InputBox(msg, {500,100}, sf::Color::White){
    
}


InputBox::InputBox()
: InputBox("Something", {500, 100}, sf::Color::White){
    
}


void InputBox::setText(string msg){
    text.setString(msg);
    setPosition(getPosition().x, getPosition().y);
}


sf::FloatRect InputBox::getLocalBounds(){
    return box.getGlobalBounds();
}

string InputBox::getText(){
    return text.getString();
}


void InputBox::setSize(float x, float y){
    box.setSize({x,y});
    text.setCharacterSize(y/2);
}


void InputBox::setPosition(float x, float y){
    box.setPosition(x, y);
    text.setPosition(x + box.getGlobalBounds().width/2 - text.getGlobalBounds().width/2,
                     y + box.getGlobalBounds().height/2 - text.getGlobalBounds().height/1.5);
}


void InputBox::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(text);
    window.draw(box);
}


