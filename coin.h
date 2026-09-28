#ifndef COIN_H
#define COIN_H
#include <SFML/Graphics.hpp>
#include "Studario.h"
#include "collision.h"
#include <SFML/Audio.hpp>
#include "score.h"
// #include "score.h"

class Coin : public sf::Drawable {
private:
    sf::Sprite coin;
    sf::Texture cointexture;
    sf::Texture moneytexture;
    float speed;
    bool isMoving=true;
    sf::SoundBuffer rewardBuffer;         // Sound buffer to hold the sound file
    sf::Sound rewardSound; 
    

public:
    Coin( float speed, float startX, float startY);
    void update(float deltaTime, Score& score);
    sf::Sprite& getSprite();
    void checkCollision(Studario& studario,Score&score);
    void resetPosition(float startX, float startY);
    void resetCollisionState();
    void render(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    void setPosition(float x, float y);
    bool hasCollided=false;
    sf::IntRect currentFrame;
    int totalFrames;         // Total frames in the sprite sheet
    float animationTimer;    // Timer to control animation speed
    float animationSpeed; 
    void stopMovement();
    void resumeMovement();
protected:
    // Override the draw function of sf::Drawable
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(coin, states);  // Draw the coin shape
    }
    
};


#endif // COIN_H