#include "Coin.h"
// Constructor
Coin::Coin(float speed, float startX, float startY)
    : speed(speed), hasCollided(false) {
    if (!cointexture.loadFromFile("coin.png")) {
        std::cerr << "Error loading coin texture!" << std::endl;
    }
    coin.setTexture(cointexture);
    if (!moneytexture.loadFromFile("money.png")) {
        std::cerr << "Error loading coin texture!" << std::endl;
    }
    coin.setTexture(cointexture);
    // Set initial position
    coin.setPosition(startX, startY);
}

// Update coin position
void Coin::update(float deltaTime, Score& score) {

    if (score.getScore() >= 70) {
        coin.setTexture(moneytexture);
    } else {
        coin.setTexture(cointexture);
    }
    if (!hasCollided) {
        coin.move(-speed * 7, 0); // Move coin left
    }

    // Reset position if the coin moves off-screen
    if (coin.getPosition().x + coin.getGlobalBounds().width < 0) {
        resetPosition(800 + coin.getGlobalBounds().width, coin.getPosition().y);
    }
}

// Reset coin position
void Coin::resetPosition(float startX, float startY) {
    coin.setPosition(startX, startY);
    hasCollided = false;
}

// Render the coin
void Coin::render(sf::RenderWindow& window) {
    window.draw(coin);
}

// Check collision with the player
void Coin::checkCollision(Studario& studario, Score& score) {
    Collision::checkCollision(coin, studario, score, rewardSound, hasCollided, +5);
}

// Reset collision state
void Coin::resetCollisionState() {
    hasCollided = false;
}

// Get the sprite
sf::Sprite& Coin::getSprite() {
    return coin;
}

sf::Vector2f Coin::getPosition() const {
    return coin.getPosition();
}

sf::FloatRect Coin::getGlobalBounds() const {
    return coin.getGlobalBounds();
}

void Coin::setPosition(float x, float y) {
    coin.setPosition(x, y);
}

void Coin::stopMovement() {
    if (!hasCollided) {
        speed = 0.0f;  // Set speed to zero to stop the movement
        coin.setPosition(-coin.getGlobalBounds().width, coin.getPosition().y);  // Move off-screen
        hasCollided = true;  // Mark the coin as collided
    }
}

void Coin::resumeMovement() {
    if (hasCollided) {
        hasCollided = false; // Reset collision state
        speed = 0.5f;        // Resume movement speed
        if (coin.getPosition().x < 0) {  // If the coin is off-screen
            coin.setPosition(800, coin.getPosition().y); // Reset to default position
        }
    }
}
