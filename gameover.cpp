#include "gameover.h"
#include <iostream>

GameOverScreen::GameOverScreen() : isLoaded(false) {}

void GameOverScreen::loadTexture(const std::string& filename) {
    if (!gameOverTexture.loadFromFile("over.png")) {
        std::cerr << "Failed to load Game Over image!" << std::endl;
    } else {
        gameOverSprite.setTexture(gameOverTexture);
        // gameOverSprite.setPosition(150, 100); // Adjust position if needed
        // isLoaded = true;
        float scaleX = 800.0f / gameOverTexture.getSize().x;
        float scaleY = 600.0f / gameOverTexture.getSize().y;
        gameOverSprite.setScale(scaleX, scaleY);

        gameOverSprite.setPosition(0, 0); // Position at the top-left corner of the window
        isLoaded = true;
    }
}

void GameOverScreen::render(sf::RenderWindow& window) {
    if (isLoaded) {
        window.draw(gameOverSprite);
    }
}