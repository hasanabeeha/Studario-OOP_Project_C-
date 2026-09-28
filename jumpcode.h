#ifndef JUMP_H
#define JUMP_H

#include "Studario.h" // Include the Studario class header
#include <SFML/Graphics.hpp> // For sf::Vector2f and related classes

class Jump {
public:
    // Constructor that takes a reference to a Studario object
    Jump(Studario& studario, float gravity);

    // Set the jump height and duration (which affect jump velocity and gravity)
    void setJumpHeightAndDuration(float desiredHeight, float desiredDuration);

    // Update the jump state based on deltaTime (time between frames)
    void update(float deltaTime);

    // Start the jump action
    void startJump();

private:
    Studario& studario; // Reference to the Studario object (no inheritance)
    float gravity; // Gravity constant affecting the jump
    float jumpVelocity; // Current velocity of the jump
    bool isJumping; // Whether the Studario is currently jumping
};

#endif // JUMP_H
