//
//  InputBox.hpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#ifndef InputBox_hpp
#define InputBox_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "States.hpp"
using namespace std;

class InputBox: public sf::Drawable, public sf::Transformable{
public:
    InputBox(string msg, sf::Vector2f vec, sf::Color color);
    InputBox(string msg, sf::Vector2f vec);
    InputBox(string msg);
    InputBox();
    void setText(string msg);
    sf::FloatRect getLocalBounds();
    string getText();
    void setSize(float x, float y);
    void setPosition(float x, float y);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    
private:
    sf::Font font;
    sf::Text text;
    sf::RectangleShape box;
};

#endif /* InputBox_hpp */
