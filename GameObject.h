// GameObject.h
#pragma once
#include <SFML/Graphics.hpp>

#include "collision.h"
class GameObject : public sf::Drawable {
public:
    virtual void update()=0;       // Update logic for the object
    virtual void checkCollision(Studario& studario, Score& scoref, Lives& live)=0; // Collision check
    virtual void render(sf::RenderWindow& window)=0;
     // Render the object
    // virtual sf::Sprite& getShape() = 0;
};