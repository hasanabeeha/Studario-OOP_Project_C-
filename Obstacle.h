#pragma once
#include <SFML/Graphics.hpp>

class Obstacle {
public:
    sf::RectangleShape shape;
    float speed;

    Obstacle(float width, float height, sf::Vector2f position, float speed)
        : speed(speed) {
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256));
        shape.setPosition(position);
    }

    void update(float deltaTime) {
        shape.move(speed * deltaTime, 0.0f);
    }

    bool isOffScreen(float windowWidth) {
        return shape.getPosition().x + shape.getSize().x < 0;
    }
};
