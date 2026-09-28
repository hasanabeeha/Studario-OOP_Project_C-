// Score.cpp
#include "Score.h"
#include <iostream>

Score::Score(const std::string& fontPath, float x, float y) {
    score = 0;  // Initialize score to 0
    isScoreActive= true;
    // Load the font (make sure the path to the font is correct)
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    // Initialize score text
    scoreText.setFont(font);
    scoreText.setCharacterSize(30); // Set text size
    scoreText.setFillColor(sf::Color::Black); // Set text color
    scoreText.setPosition(x, y); // Set position at top-right corner
}

void Score::update(sf::RenderWindow& window) {
    // Update the score every second
    if (isScoreActive && scoreClock.getElapsedTime().asSeconds() >= 1) {
        score++; // Increment score
        scoreClock.restart(); // Restart the clock
    }

    // Update the score text
    scoreText.setString("SCORE: " + std::to_string(score));
    float x = window.getSize().x - scoreText.getLocalBounds().width - 10; // 10px padding from right
    float y = 10; // 10px padding from the top
    scoreText.setPosition(x, y);
    
}

void Score::draw(sf::RenderWindow& window) {
    // Draw the score text to the window
    window.draw(scoreText);
}

sf::Text Score::getScoreText() const {
    return scoreText;
}
void Score::updateScore(int value) {
    score += value; // Add the value to the score
}
int Score::getScore() const {
    return score;
}
void Score::stopScore() {
    isScoreActive = false; // Disable score updates
    score = score;
}