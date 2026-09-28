#include "degree.h"

Degree::Degree(float x, float y, float speed, const std::string &textureFile)
    : speed(speed), hasCollided(false)
{
    if (!degreeTexture.loadFromFile("degree.png"))
    {
        std::cerr << "Error loading degree texture" << std::endl;
    }

    degreeSprite.setTexture(degreeTexture);
    degreeSprite.setScale(0.3f, 0.3f);
    degreeSprite.setPosition(x, y);
}

void Degree::update()
{
    if (hasCollided)
    {
        return;
    }

    // Update horizontal movement
    degreeSprite.move(-speed * 0.2f, 0);

    // Sinusoidal vertical movement
    float amplitude = 100.0f; // Amplitude of the sine wave
    float frequency = 2.0f;   // Frequency of the oscillation (adjust as needed)

    float baseY = 200.0f; // Center of the sinusoidal wave (adjust as needed)
    float newY = baseY + amplitude * std::sin(frequency * degreeclock.getElapsedTime().asSeconds());
    degreeSprite.setPosition(degreeSprite.getPosition().x, newY);

    degreeSprite.setPosition(degreeSprite.getPosition().x, newY);

    // Reset position if off-screen
    if (degreeSprite.getPosition().x < -degreeSprite.getGlobalBounds().width)
    {
        resetPosition(800, degreeSprite.getPosition().y); // Adjust for screen width
    }
}

void Degree::resetPosition(float x, float y)
{
    // degreeSprite.setPosition(x, y); // Reset to specified coordinates
    if (hasCollided)
    {
        degreeSprite.setPosition(x, y); // Reset to specified coordinates
    }
}

void Degree::render(sf::RenderWindow &window)
{

    window.draw(degreeSprite);
}

void Degree::checkCollision(Score &score, Studario &studario)
{
    sf::FloatRect degreeBounds = getGlobalBounds();
    sf::FloatRect studarioBounds = studario.getSprite().getGlobalBounds();
    float shrinkFactor = 5.0f; // Adjust the shrink factor (smaller number to make collision area closer to actual size)

    // Get the degree and character bounding boxes
    degreeBounds.left += shrinkFactor * 35;
    degreeBounds.top -= shrinkFactor * 63;
    degreeBounds.width += 20 * shrinkFactor;
    degreeBounds.height -= 2 * shrinkFactor;

    sf::FloatRect characterBounds = studario.getSprite().getGlobalBounds();
    characterBounds.left -= shrinkFactor * 28;
    characterBounds.top += shrinkFactor;
    characterBounds.width += 20 * shrinkFactor;
    characterBounds.height -= 2 * shrinkFactor;
    // Check for intersection between Degree and Studario
    if (degreeBounds.intersects(studarioBounds) && !hasCollided)
    {
        // Mark as collided
        hasCollided = true;

        // Play collision sound
        // collisionSound.stop();
        // collisionSound.play();

        // Deduct score
        score.updateScore(+20);

        // Stop degree's movement or handle collision response
        stopMovement();

        std::cout << "Collision with degree!" << std::endl;
    }

    // Handle post-collision behavior
    if (hasCollided)
    {
        // Optionally reset position or remove the degree from active play
        resetPosition(-degreeSprite.getGlobalBounds().width, degreeSprite.getPosition().y); // Move off-screen
    }
}

void Degree::stopMovement()
{
    speed = 0.0f;
    degreeSprite.setPosition(-degreeSprite.getGlobalBounds().width, degreeSprite.getPosition().y); // Move to the left off-screen
};
void Degree::resumeMovement()
{
    // Resume movement by setting the speed back to the provided value
    speed = 0.5f;
}

sf::Vector2f Degree::getPosition() const
{
    // Return the current position of the degree sprite
    return degreeSprite.getPosition();
}
sf::FloatRect Degree::getGlobalBounds() const
{
    return degreeSprite.getGlobalBounds();
}