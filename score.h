// Score.h
#pragma once
#include <SFML/Graphics.hpp>

class Score {
public:
    // Constructor
    Score(const std::string& fontPath, float x, float y);

    // Update score every second
    void update(sf::RenderWindow& window);
    void updateScore(int value);
    int getScore() const;
    int currentscore(){
        return score;
    }
    // Draw score to the window
    void draw(sf::RenderWindow& window);

    // Getter for the score text
    sf::Text getScoreText() const;
void stopScore(); // Function to stop the score

private:
    int score;
    bool isScoreActive;  // Current score
    sf::Clock scoreClock;  // Clock to track time for incrementing score
    sf::Font font;  // Font for score text
    sf::Text scoreText;  // Text object for displaying score
};

