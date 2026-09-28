#ifndef HEART_HPP
#define HEART_HPP

#include <SFML/Graphics.hpp>

class heart : public sf::Drawable {
public:
    // Constructor to initialize the heart at a specific position
    heart();
    heart(float x, float y, float size = 10.0f, sf::Color color = sf::Color::Red);

    // Set the position of the heart
    void setPosition(float x, float y);

    // Set the color of the heart
    void setColor(sf::Color color);

private:
    // Overriding the draw function to render the heart
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    // Private member variables for the heart's components
    sf::CircleShape leftCircle;
    sf::CircleShape rightCircle;
    sf::ConvexShape bottomTriangle;
};

#endif // HEART_HPP
