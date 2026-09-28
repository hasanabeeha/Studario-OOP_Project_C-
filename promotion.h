#ifndef PROMOTION_H
#define PROMOTION_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"
#include <cmath>

class Promotion : public sf::Drawable{
private:
    sf::Texture promotionTexture;
    sf::Sprite promotionSprite;
    sf::Clock promotionclock; 
    sf::SoundBuffer rewardBuffer;         // Sound buffer to hold the sound file
    sf::Sound rewardSound; 
    float speed;


public:
    Promotion(float x, float y, float speed, const std::string& textureFile);
    bool hasCollided=false;
    void update();
     void resetPosition(float x, float y);
    void render(sf::RenderWindow& window);
    void  checkCollision(Score& score,Studario& studario) ;
        void stopMovement();
    // sf::Sprite& getShape()override;
    sf::Sprite getSprite();
    void resumeMovement();
    sf::Vector2f getPosition()const;
    sf::FloatRect getGlobalBounds() const;
protected:
    // Override the draw function of sf::Drawable
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(promotionSprite, states);  // Draw the coin sprite
    }
};

#endif // PROMOTION_H