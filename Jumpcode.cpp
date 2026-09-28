#include "Jump.h"
#include "Studario.h"
#include <cmath>

Jump::Jump(Studario& studario, float gravity)
    : studario(studario), gravity(gravity), jumpVelocity(0), isJumping(false) {
    studario.setPosition(50.0f, 420.0f - studario.getRadius() * 2); // Initial position on screen
}

void Jump::setJumpHeightAndDuration(float desiredHeight, float desiredDuration) {
    // Calculate initial velocity for the desired height and gravity for the duration
    jumpVelocity = -std::sqrt(2 * gravity * desiredHeight);
    gravity = (2 * -jumpVelocity) / desiredDuration;
}

void Jump::update(float deltaTime) {
    if (isJumping) {
        jumpVelocity += gravity * deltaTime; // Apply gravity to velocity over time
        sf::Vector2f movement(0, jumpVelocity * deltaTime); // Scaled by deltaTime for smooth movement
        studario.move(movement); // Move the character's Studario

        // Check for landing
        if (studario.getPosition().y >= 420 - studario.getRadius() * 2) {
            isJumping = false;
            jumpVelocity = 0.0f;
            studario.setPosition(studario.getPosition().x, 420.0f - studario.getRadius() * 2); // Reset to ground level
        }
    }
}

void Jump::startJump() {
    if (!isJumping) {
        isJumping = true;
        jumpVelocity = -std::sqrt(2 * gravity * 200.0f); // Recalculate velocity based on the height (200 is an example height)
    }
}
