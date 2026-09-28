#include <SFML/Graphics.hpp>

class Character {
protected:
    sf::CircleShape shape;
    float speed;

public:
    // Character(){};
    Character(float radius, float speed);
    virtual ~Character() {}
    virtual void update();
    sf::CircleShape& getShape();
    
};

