#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <SFML/Graphics.hpp>

class GameOverScreen {
public:
    GameOverScreen();
    void loadTexture(const std::string& filename);
    void render(sf::RenderWindow& window);

private:
    sf::Texture gameOverTexture;
    sf::Sprite gameOverSprite;
    bool isLoaded;
};

#endif // GAMEOVERSCREEN_H