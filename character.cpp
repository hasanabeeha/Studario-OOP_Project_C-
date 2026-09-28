#include "character.h"

Character::Character(float radius, float speed) : shape(radius), speed(speed) {
    shape.setFillColor(sf::Color::Red);
}

void Character::update() {
    // Character update logic, if any
}

sf::CircleShape& Character::getShape() {
    return shape;
}
