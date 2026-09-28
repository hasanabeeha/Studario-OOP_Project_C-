#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
class Studario {
public:
    sf::Clock clock;

    Studario(float speed, float gravity);

    void update(float deltaTime);
    void jump();
    bool isOnGround();
    bool jumpornot(){
        if(isJumping){
        return true;}
        else return false;

    };
    sf::Sprite& getSprite();
    void updateCharacter(int score);
private:
    float speed;
    bool isJumping;   
    float gravity;
    float groundLevel;
    float velocityY;   

    sf::Texture runTexture;  
    sf::Texture jumpTexture;
    sf::Sprite sprite;
    sf::Texture secondRunTexture; 
    sf::Texture secondJumpTexture;
    bool isSecondCharacterActive; 

    sf::IntRect walkingFrame;
    float animationTimer;
    float animationDuration;
    int currentFrame;
    int totalFrames;
    int frameWidth;
    int frameHeight;
};
