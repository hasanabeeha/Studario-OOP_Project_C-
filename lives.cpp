#include "lives.h"
#include <iostream>
Lives::Lives(){};
Lives::Lives(const std::string& fontPath, float x, float y) {
    // Load the font (make sure the path to the font is correct)
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    // Initialize "HEALTH" text
    livesText.setFont(font);
    livesText.setString("HEALTH:");
    livesText.setCharacterSize(19);            // Set text size
    livesText.setFillColor(sf::Color::Black);  // Set text color
    livesText.setPosition(x, y);               // Set position for "HEALTH" text

    // Create hearts (initially set to 3 hearts, adjust as needed)
    for (int i = 0; i < 3; ++i) {
        heart heart(x + 80 + (i * 40)+18, y+8, 10.0f, sf::Color::Red);  // Position hearts next to "HEALTH:"
        hearts.push_back(heart);
    }
}

void Lives::update(int lives) {
    // Ensure we do not exceed the number of hearts and start from the last heart
    for (int i = 0; i < Collision::collisionCount; ++i) {
        if (i < hearts.size()) {
            hearts[i].setColor(sf::Color(192, 192, 192));  // Turn the heart grey (empty)
        }
    }
}


void Lives::draw(sf::RenderWindow& window) {
    // Draw the "HEALTH" text and the hearts
    window.draw(livesText);
    for (const auto& heart : hearts) {
        window.draw(heart);
    }
}
void Lives::decrementLives() {
    if (!hearts.empty()) {
        // Reduce lives by turning one heart grey
        hearts.back().setColor(sf::Color(192, 192, 192));  // Turn the last active heart grey
        hearts.pop_back();  // Remove the heart from the active list
    }
}