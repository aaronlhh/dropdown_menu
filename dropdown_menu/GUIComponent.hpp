//
//  GUIComponent.h
//  dropdown_menu
//
//  Created by Aaron Lin on 4/28/21.
//

#ifndef GUIComponent_hpp
#define GUIComponent_hpp

#include <SFML/Graphics.hpp>
#include "SnapshotInterface.hpp"
#include "EventHandler.hpp"
#include "States.hpp"

class GUIComponent: public sf::Drawable, public sf::Transformable, public SnapshotInterface,
            public EventHandler, public States{
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

    //from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;

    
private:
    
    
    
    
};

#endif /* GUIComponent_hpp */
