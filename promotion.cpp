#include "promotion.h"

Promotion::Promotion(float x, float y, float speed, const std::string &textureFile)
    : speed(speed), hasCollided(false)
{
    if (!promotionTexture.loadFromFile("promotion.png"))
    {
        std::cerr << "Error loading promotion texture" << std::endl;
    }

    promotionSprite.setTexture(promotionTexture);
    promotionSprite.setScale(0.3f, 0.3f);
    promotionSprite.setPosition(x, y);
}

void Promotion::update()
{
    if (hasCollided)
    {
        // Stop updating if the promotion has collided
        return;
    }

    // Update horizontal movement
    promotionSprite.move(-speed * 0.2f, 0);

    // Sinusoidal vertical movement
    float amplitude = 100.0f; // Amplitude of the sine wave
    float frequency = 2.0f;   // Frequency of the oscillation (adjust as needed)

    float baseY = 200.0f; // Center of the sinusoidal wave (adjust as needed)
    float newY = baseY + amplitude * std::sin(frequency * promotionclock.getElapsedTime().asSeconds());
    promotionSprite.setPosition(promotionSprite.getPosition().x, newY);

    promotionSprite.setPosition(promotionSprite.getPosition().x, newY);

    // Reset position if off-screen
    if (promotionSprite.getPosition().x < -promotionSprite.getGlobalBounds().width)
    {
        resetPosition(800, promotionSprite.getPosition().y); // Adjust for screen width
    }
}

void Promotion::resetPosition(float x, float y)
{
    // promotionSprite.setPosition(x, y); // Reset to specified coordinates
    if (hasCollided)
    {
        promotionSprite.setPosition(x, y); // Reset to specified coordinates
    }
}

void Promotion::render(sf::RenderWindow &window)
{

    window.draw(promotionSprite);
}

void Promotion::checkCollision(Score &score, Studario &studario)
{
    sf::FloatRect promotionBounds = getGlobalBounds();
    sf::FloatRect studarioBounds = studario.getSprite().getGlobalBounds();
    float shrinkFactor = 5.0f; // Adjust the shrink factor (smaller number to make collision area closer to actual size)

    // Get the promotion and character bounding boxes
    promotionBounds.left += shrinkFactor * 35;
    promotionBounds.top -= shrinkFactor * 63;
    promotionBounds.width += 20 * shrinkFactor;
    promotionBounds.height -= 2 * shrinkFactor;

    sf::FloatRect characterBounds = studario.getSprite().getGlobalBounds();
    characterBounds.left -= shrinkFactor * 28;
    characterBounds.top += shrinkFactor;
    characterBounds.width += 20 * shrinkFactor;
    characterBounds.height -= 2 * shrinkFactor;
    // Check for intersection between promotion and Studario
    if (promotionBounds.intersects(studarioBounds) && !hasCollided)
    {
        // Mark as collided
        hasCollided = true;

        // Play collision sound
        // collisionSound.stop();
        // collisionSound.play();

        // Deduct score
        score.updateScore(+20);

        // Stop promotion's movement or handle collision response
        stopMovement();

        std::cout << "Collision with promotion!" << std::endl;
    }

    // Handle post-collision behavior
    if (hasCollided)
    {
        // Optionally reset position or remove the promotion from active play
        resetPosition(-promotionSprite.getGlobalBounds().width, promotionSprite.getPosition().y); // Move off-screen
    }
}

void Promotion::stopMovement()
{
    speed = 0.0f;
    promotionSprite.setPosition(-promotionSprite.getGlobalBounds().width, promotionSprite.getPosition().y); // Move to the left off-screen
};
void Promotion::resumeMovement()
{
    // Resume movement by setting the speed back to the provided value
    speed = 0.5f;
}

sf::Vector2f Promotion::getPosition() const
{
    // Return the current position of the promotion sprite
    return promotionSprite.getPosition();
}
sf::FloatRect Promotion::getGlobalBounds() const
{
    return promotionSprite.getGlobalBounds();
}