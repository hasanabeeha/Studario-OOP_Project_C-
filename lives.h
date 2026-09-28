#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "heart.h"  // Include the heart shape header
#include "collision.h"
// #include "collision.h"
class Lives {
public:
Lives();
    Lives(const std::string& fontPath, float x, float y);

    void update(int lives);  // Update lives
    void draw(sf::RenderWindow& window);
    void updateHeartsColor(int collisionCount);
    void decrementLives() ;
    int getRemainingLives() const ;
private:
    sf::Font font;          // Font for lives text
    sf::Text livesText;     // Text object for displaying "HEALTH:"
    std::vector<heart> hearts;  // Hearts to represent lives
};
