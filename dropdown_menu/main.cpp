//
//  main.cpp
//  dropdown_menu
//
//  Created by Aaron Lin on 4/27/21.
//

#include <iostream>

#include <SFML/Graphics.hpp>
#include "DropdownMenu.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "dropdown");
    vector<string> vec{"abcdef", "Apples", "Bananas", "Hello", "Hello World!"};
    DropdownMenu menu(vec);
    menu.setPosition(100, 100);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            menu.addEventHandler(window, event);
        }
        menu.update();
        window.clear();
        window.draw(menu);
        window.display();
    }
}
