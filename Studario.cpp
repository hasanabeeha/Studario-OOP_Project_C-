#include "Studario.h"
#include "score.h"

Studario::Studario(float speed, float gravity)
    : speed(speed), gravity(gravity), isJumping(false),
      animationTimer(0), currentFrame(0), totalFrames(10),
      animationDuration(0.1f), velocityY(0), frameWidth(128), frameHeight(128),
      groundLevel(320.0f), isSecondCharacterActive(false)
{//constructor
//sprites loading:
    if (!runTexture.loadFromFile("Run.png"))
    {
        std::cerr << "Error loading walking texture!" << std::endl;
    }

    if (!jumpTexture.loadFromFile("Jump.png"))
    {
        std::cerr << "Error loading jumping texture!" << std::endl;
    }
    if (!secondRunTexture.loadFromFile("Run1.png"))
    {
        std::cerr << "Error loading second character texture!" << std::endl;
    }
    if (!secondJumpTexture.loadFromFile("Jump1.png"))
    {
        std::cerr << "Error loading second character jump texture!" << std::endl;
    }

    sprite.setTexture(runTexture);
    sprite.setOrigin(frameWidth / 2, frameHeight / 2);
    sprite.setPosition(160.0f, groundLevel);
    sprite.setScale(3, 3);

    walkingFrame = sf::IntRect(0, 0, frameWidth, frameHeight);
    sprite.setTextureRect(walkingFrame);
}

void Studario::update(float deltaTime)
{//animation:
    animationTimer += deltaTime;

    if (!isJumping)
    {

        if (animationTimer >= animationDuration)
        {
            currentFrame = (currentFrame + 1) % totalFrames;

            if (isSecondCharacterActive)
            {
                sprite.setTexture(secondRunTexture);
            }
            else
            {
                sprite.setTexture(runTexture);
            }

            walkingFrame.left = currentFrame * frameWidth;
            sprite.setTextureRect(walkingFrame);
            animationTimer = 0.0f;
        }
    }
//applying gravity if character is in air
    if (!isOnGround() || isJumping)
    {
        velocityY += gravity * deltaTime * 0.7;
        sprite.move(0, velocityY * deltaTime);

        if (isJumping)
        {
            sprite.setTexture(isSecondCharacterActive ? secondJumpTexture : jumpTexture);
        }
    }
//landing
    if (sprite.getPosition().y >= groundLevel)
    {
        sprite.setPosition(sprite.getPosition().x, groundLevel);
        velocityY = 0;
        isJumping = false;
        sprite.setTexture(isSecondCharacterActive ? secondRunTexture : runTexture);
        sprite.setTextureRect(walkingFrame);
    }
}
//jump function
void Studario::jump()
{
    if (isOnGround() && !isJumping)
    {
        isJumping = true;
        velocityY = -300.0f; // Jump strength (negative to move up)
    }
}
//if character is on ground
bool Studario::isOnGround()
{
    return sprite.getPosition().y >= groundLevel;
}

sf::Sprite &Studario::getSprite()
{
    return sprite;
}
void Studario::updateCharacter(int score)//to enable the second character
{
    if (score >= 70 && !isSecondCharacterActive)
    {
        isSecondCharacterActive = true;
        currentFrame = 0;
        sprite.setTexture(secondRunTexture);
        sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
    }
}
