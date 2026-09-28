#include <SFML/Graphics.hpp>
#include "heart.h"

// Constructor definition
heart::heart(){};
heart::heart(float x, float y, float size, sf::Color color)
    : leftCircle(size-3), rightCircle(size-3), bottomTriangle() {

    // Configure the left circle
    leftCircle.setFillColor(color);
    leftCircle.setOrigin(size-6, size); // Set origin to center of the circle
    leftCircle.setPosition(x - size+1 / 2, y);  // Position to the left

    // Configure the right circle
    rightCircle.setFillColor(color);
    rightCircle.setOrigin(size+3, size); // Set origin to center of the circle
    rightCircle.setPosition(x + size-1 / 2, y);  // Position to the right

    // Configure the triangle
    bottomTriangle.setPointCount(3);
    bottomTriangle.setPoint(0, sf::Vector2f(x-5 - size, y-2));      // Top-left point
    bottomTriangle.setPoint(1.5, sf::Vector2f(x +2+ size, y-2));      // Top-right point
    bottomTriangle.setPoint(2, sf::Vector2f(x-1, y + size * 2-4));  // Bottom point
    bottomTriangle.setFillColor(color);
}

// Set the position of the heart
void heart::setPosition(float x, float y) {
    leftCircle.setPosition(x - leftCircle.getRadius() / 2-2, y);
    rightCircle.setPosition(x + rightCircle.getRadius() / 2-2, y);
    bottomTriangle.setPoint(0, sf::Vector2f(x - leftCircle.getRadius()-2, y));
    bottomTriangle.setPoint(1, sf::Vector2f(x + rightCircle.getRadius()-2, y));
    bottomTriangle.setPoint(2, sf::Vector2f(x-2, y + leftCircle.getRadius() * 2));
}

// Set the color of the heart
void heart::setColor(sf::Color color) {
    leftCircle.setFillColor(color);
    rightCircle.setFillColor(color);
    bottomTriangle.setFillColor(color);
}

// Draw function to render the heart
void heart::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(leftCircle, states);
    target.draw(rightCircle, states);
    target.draw(bottomTriangle, states);
}
