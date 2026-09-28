#include "Collision.h"
#include <iostream>

Collision::Collision() {}
int Collision::collisionCount = 0;
void Collision::checkCollision(sf::RectangleShape &obstacle, Studario &studario, Score &score, sf::Sound &collisionSound, bool &hasCollided, int scorePenalty)
{
    // Shrink the bounds to adjust for natural collision detection
    float shrinkFactor = 5.0f;
    sf::FloatRect obstacleBounds = obstacle.getGlobalBounds();
    obstacleBounds.left += shrinkFactor * 38;
    obstacleBounds.top -= shrinkFactor * 73;
    obstacleBounds.width -= 10 * shrinkFactor;
    obstacleBounds.height -= 2 * shrinkFactor;

    sf::FloatRect characterBounds = studario.getSprite().getGlobalBounds();
    characterBounds.left -= shrinkFactor;
    characterBounds.top += shrinkFactor;
    characterBounds.width -= 2 * shrinkFactor;
    characterBounds.height -= 2 * shrinkFactor;

    // Check if the player is on the ground or jumping
    bool isOnGround = studario.isOnGround();
    bool isJumping = studario.jumpornot();

    // Check if the character's bounds intersect with the obstacle's bounds
    bool intersect = obstacleBounds.intersects(characterBounds);

    static bool hasExitedCollision = true; // Tracks whether the obstacle has left collision

    // Only detect collision when the obstacle enters the collision area
    if (!isJumping && intersect && hasExitedCollision)
    {
        std::cout << "Collision detected!" << std::endl;

        collisionSound.stop(); // Stop any previous sound
        collisionSound.play(); // Play collision sound

        collisionCount++; // Increment collision count
        std::cout << "Collision count: " << collisionCount << std::endl;

        score.updateScore(scorePenalty); // Deduct points for collision

        // Optional: Reset score if below a threshold (e.g., 5)
        if (score.getScore() < 5)
        {
            score.updateScore(-score.getScore()); // Reset score to 0
        }

        // On the third collision, set score to 50
        // if (collisionCount == 3) {
        //     std::cout << "Score has been set to 50 after third collision!" << std::endl;
        //     // score.updateScore(-score.getScore());  // Reset score
        // }

        hasExitedCollision = false; // Mark as currently in collision
    }

    // Reset collision tracking once the obstacle has fully moved out of collision bounds
    if (!intersect)
    {
        hasExitedCollision = true;
    }

    // Reset collision flag when the player is not on the ground
    if (!isOnGround)
    {
        hasCollided = false; // Allow re-collision when the player is back on the ground
    }
}
void Collision::checkCollision(sf::Sprite &obstacle, Studario &studario, Score &score, sf::Sound &collisionSound, bool &hasCollided, int scorePenalty)
{
    // Shrink the bounds to adjust for natural collision detection
    float shrinkFactor = 5.0f; // Adjust the shrink factor (smaller number to make collision area closer to actual size)

    // Get the obstacle and character bounding boxes
    sf::FloatRect obstacleBounds = obstacle.getGlobalBounds();
    obstacleBounds.left += shrinkFactor;
    obstacleBounds.top -= shrinkFactor * 63;
    obstacleBounds.width -= 2 * shrinkFactor;
    obstacleBounds.height -= 2 * shrinkFactor;

    sf::FloatRect characterBounds = studario.getSprite().getGlobalBounds();
    characterBounds.left -= shrinkFactor * 28;
    characterBounds.top += shrinkFactor;
    characterBounds.width -= 2 * shrinkFactor;
    characterBounds.height -= 2 * shrinkFactor;

    // Check if the player is on the ground or jumping
    bool isOnGround = studario.isOnGround();
    bool isJumping = studario.jumpornot();

    // Check if the character's bounds intersect with the obstacle's bounds
    bool intersect = obstacleBounds.intersects(characterBounds);

    static bool hasExitedCollision = true; // Tracks whether the obstacle has left collision

    // Only detect collision when the obstacle enters the collision area
    if (!isJumping && intersect && hasExitedCollision)
    {
        std::cout << "Collision with coin!" << std::endl;

        collisionSound.stop(); // Stop any previous sound
        collisionSound.play(); // Play collision sound
                               // Increment collision count

        score.updateScore(scorePenalty); // Deduct points for collision

        hasExitedCollision = false; // Mark as currently in collision
    }

    // Reset collision tracking once the obstacle has fully moved out of collision bounds
    if (!intersect)
    {
        hasExitedCollision = true;
    }

    // Reset collision flag when the player is not on the ground
    if (!isOnGround)
    {
        hasCollided = false; // Allow re-collision when the player is back on the ground
    }
}