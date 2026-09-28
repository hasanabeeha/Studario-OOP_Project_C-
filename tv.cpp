// #include "TV.h"
// #include <iostream>

// TV::TV() {
//     // Set x and y for the position, you can adjust these values
//     float x = 1350.f;  // Adjust as needed
//     float y = 460.f;  // Adjust as needed

//     // TV Body
//     tvBody.setSize(sf::Vector2f(90.f, 50.f)); // Fit the TV body into (90, 50)
//     tvBody.setPosition(x, y);
//     tvBody.setFillColor(sf::Color(255, 140, 0)); // Orange color
//     tvBody.setOutlineColor(sf::Color::Black);
//     tvBody.setOutlineThickness(2.f);

//     // TV Screen
//     screen.setSize(sf::Vector2f(70.f, 35.f)); // Scaled to fit within the TV body
//     screen.setPosition(x + 10.f, y + 7.f); // Positioned inside the TV body
//     screen.setFillColor(sf::Color(0, 191, 255)); // Light blue
//     screen.setOutlineColor(sf::Color::Black);
//     screen.setOutlineThickness(1.f);

//     // Left Knob
//     leftKnob.setRadius(3.f); // Scaled for smaller TV
//     leftKnob.setPosition(x + 80.f, y + 15.f);
//     leftKnob.setFillColor(sf::Color(220, 20, 60)); // Red
//     leftKnob.setOutlineColor(sf::Color::Black);
//     leftKnob.setOutlineThickness(1.f);

//     // Right Knob
//     rightKnob.setRadius(3.f); // Scaled for smaller TV
//     rightKnob.setPosition(x + 80.f, y + 25.f);
//     rightKnob.setFillColor(sf::Color(30, 144, 255)); // Blue
//     rightKnob.setOutlineColor(sf::Color::Black);
//     rightKnob.setOutlineThickness(1.f);

//     // Antenna Base
//     antennaBase.setRadius(5.f); // Adjusted size
//     antennaBase.setPosition(x + 40.f, y - 8.f);
//     antennaBase.setFillColor(sf::Color(255, 140, 0));
//     antennaBase.setOutlineColor(sf::Color::Black);
//     antennaBase.setOutlineThickness(1.f);

//     // Antenna Left
//     antennaLeft.setSize(sf::Vector2f(15.f, 1.f)); // Adjusted size
//     antennaLeft.setPosition(x + 45.f, y); // Adjusted position
//     antennaLeft.setFillColor(sf::Color::Black);
//     antennaLeft.setRotation(-115.f);

//     // Antenna Right
//     antennaRight.setSize(sf::Vector2f(15.f, 1.f)); // Adjusted size
//     antennaRight.setPosition(x + 45.f, y); // Adjusted position
//     antennaRight.setFillColor(sf::Color::Black);
//     antennaRight.setRotation(-65.f);

//     // TV Legs
//     leftLeg.setSize(sf::Vector2f(10.f, 10.f)); // Adjusted size
//     leftLeg.setPosition(x + 10.f, y + 50.f); // Positioned at bottom left
//     leftLeg.setFillColor(sf::Color(101, 67, 33));

//     rightLeg.setSize(sf::Vector2f(10.f, 10.f)); // Adjusted size
//     rightLeg.setPosition(x + 70.f, y + 50.f); // Positioned at bottom right
//     rightLeg.setFillColor(sf::Color(101, 67, 33));

//     // Load Font
//     if (!font.loadFromFile("fonts/arial.ttf")) {
//         std::cerr << "Failed to load font!" << std::endl;
//     }

//     // Text (TV)
//     tvText.setFont(font);
//     tvText.setString("TV");
//     tvText.setCharacterSize(12); // Scaled-down size
//     tvText.setFillColor(sf::Color(101, 67, 33));
//     tvText.setOutlineColor(sf::Color::White);
//     tvText.setOutlineThickness(0.5f);
//     tvText.setPosition(x + 32.f, y + 15.f); // Centered on the screen
// }
//  float velocity = 0.2f;
// void TV::update() {
//     // Get current position of the TV body
//     float x = tvBody.getPosition().x;

//     // Move the TV to the left
//     tvBody.move(-velocity, 0); // Moves left by velocity pixels

//     // If the TV goes off the screen on the left, reset to the right
//     if (x + tvBody.getSize().x < 0) {
//         tvBody.setPosition(800.f, tvBody.getPosition().y); // Reset to the right
//     }

//     // Update other components' positions based on the TV body
//     screen.setPosition(tvBody.getPosition().x + 10.f, tvBody.getPosition().y + 7.f);
//     leftKnob.setPosition(tvBody.getPosition().x + 80.f, tvBody.getPosition().y + 15.f);
//     rightKnob.setPosition(tvBody.getPosition().x + 80.f, tvBody.getPosition().y + 25.f);
//     antennaBase.setPosition(tvBody.getPosition().x + 40.f, tvBody.getPosition().y - 8.f);
//     antennaLeft.setPosition(tvBody.getPosition().x + 45.f, tvBody.getPosition().y);
//     antennaRight.setPosition(tvBody.getPosition().x + 45.f, tvBody.getPosition().y);
//     leftLeg.setPosition(tvBody.getPosition().x + 10.f, tvBody.getPosition().y + 50.f);
//     rightLeg.setPosition(tvBody.getPosition().x + 70.f, tvBody.getPosition().y + 50.f);
//     tvText.setPosition(tvBody.getPosition().x + 32.f, tvBody.getPosition().y + 15.f);
// }

// void TV::render(sf::RenderWindow& window) {
//     window.draw(antennaBase);
//     window.draw(antennaLeft);
//     window.draw(antennaRight);
//     window.draw(leftLeg);
//     window.draw(rightLeg);
//     window.draw(tvBody);
//     window.draw(screen);
//     window.draw(leftKnob);
//     window.draw(rightKnob);
//     window.draw(tvText);
// }



#include "TV.h"
#include <iostream>

TV::TV() {
    // Set x and y for the position, you can adjust these values
    float x = 1350.f;  // Adjust as needed
    float y = 480.f;  // Adjust as needed
    damageSound.setBuffer(damageBuffer);
    // TV Body
    tvBody.setSize(sf::Vector2f(90.f, 50.f)); // Fit the TV body into (90, 50)
    tvBody.setPosition(x, y);
    tvBody.setFillColor(sf::Color(255, 140, 0)); // Orange color
    tvBody.setOutlineColor(sf::Color::Black);
    tvBody.setOutlineThickness(2.f);

    // TV Screen
    screen.setSize(sf::Vector2f(70.f, 35.f)); // Scaled to fit within the TV body
    screen.setPosition(x + 10.f, y + 7.f); // Positioned inside the TV body
    screen.setFillColor(sf::Color(0, 191, 255)); // Light blue
    screen.setOutlineColor(sf::Color::Black);
    screen.setOutlineThickness(1.f);

    // Left Knob
    leftKnob.setRadius(3.f); // Scaled for smaller TV
    leftKnob.setPosition(x + 80.f, y + 15.f);
    leftKnob.setFillColor(sf::Color(220, 20, 60)); // Red
    leftKnob.setOutlineColor(sf::Color::Black);
    leftKnob.setOutlineThickness(1.f);

    // Right Knob
    rightKnob.setRadius(3.f); // Scaled for smaller TV
    rightKnob.setPosition(x + 80.f, y + 25.f);
    rightKnob.setFillColor(sf::Color(30, 144, 255)); // Blue
    rightKnob.setOutlineColor(sf::Color::Black);
    rightKnob.setOutlineThickness(1.f);

    // Antenna Base
    antennaBase.setRadius(5.f); // Adjusted size
    antennaBase.setPosition(x + 40.f, y - 8.f);
    antennaBase.setFillColor(sf::Color(255, 140, 0));
    antennaBase.setOutlineColor(sf::Color::Black);
    antennaBase.setOutlineThickness(1.f);

    // Antenna Left
    antennaLeft.setSize(sf::Vector2f(15.f, 1.f)); // Adjusted size
    antennaLeft.setPosition(x + 45.f, y); // Adjusted position
    antennaLeft.setFillColor(sf::Color::Black);
    antennaLeft.setRotation(-115.f);

    // Antenna Right
    antennaRight.setSize(sf::Vector2f(15.f, 1.f)); // Adjusted size
    antennaRight.setPosition(x + 45.f, y); // Adjusted position
    antennaRight.setFillColor(sf::Color::Black);
    antennaRight.setRotation(-65.f);

    // TV Legs
    leftLeg.setSize(sf::Vector2f(10.f, 10.f)); // Adjusted size
    leftLeg.setPosition(x + 10.f, y + 50.f); // Positioned at bottom left
    leftLeg.setFillColor(sf::Color(101, 67, 33));

    rightLeg.setSize(sf::Vector2f(10.f, 10.f)); // Adjusted size
    rightLeg.setPosition(x + 70.f, y + 50.f); // Positioned at bottom right
    rightLeg.setFillColor(sf::Color(101, 67, 33));

    // Load Font
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }
    if (!damageBuffer.loadFromFile("damage.wav")) {
    std::cerr << "Failed to load damage sound!" << std::endl;
    }

    // Text (TV)
    tvText.setFont(font);
    tvText.setString("TV");
    tvText.setCharacterSize(12); // Scaled-down size
    tvText.setFillColor(sf::Color(101, 67, 33));
    tvText.setOutlineColor(sf::Color::White);
    tvText.setOutlineThickness(0.5f);
    tvText.setPosition(x + 32.f, y + 15.f); // Centered on the screen
}
 float velocity = 0.5f;
void TV::update() {
    // Get the current position of the TV body
    float x = tvBody.getPosition().x;

    // Scale factor
    float scale = 0.55f;

    // Move the TV to the left
    if (collisionCount < 300) {
        tvBody.move(-velocity, 0); // Move TV to the left by 'velocity' pixels
        // Update the positions of the other components relative to the new position of the TV body
        screen.setPosition(tvBody.getPosition().x + 10.f * scale, tvBody.getPosition().y + 7.f * scale);
        leftKnob.setPosition(tvBody.getPosition().x + 80.f * scale, tvBody.getPosition().y + 15.f * scale);
        rightKnob.setPosition(tvBody.getPosition().x + 80.f * scale, tvBody.getPosition().y + 25.f * scale);
        antennaBase.setPosition(tvBody.getPosition().x + 40.f * scale, tvBody.getPosition().y - 8.f * scale);
        antennaLeft.setPosition(tvBody.getPosition().x + 45.f * scale, tvBody.getPosition().y);
        antennaRight.setPosition(tvBody.getPosition().x + 45.f * scale, tvBody.getPosition().y );
        leftLeg.setPosition(tvBody.getPosition().x + 10.f * scale, tvBody.getPosition().y + 50.f * scale);
        rightLeg.setPosition(tvBody.getPosition().x + 70.f * scale, tvBody.getPosition().y + 50.f * scale);
        tvText.setPosition(tvBody.getPosition().x + 32.f * scale, tvBody.getPosition().y + 15.f * scale);
    } else {
        velocity = 0;  // Stop movement after collisionCount exceeds 300
    }

    // If the TV goes off the screen on the left, reset to the right
    if (x + tvBody.getSize().x < 0) {
        tvBody.setPosition(800.f, tvBody.getPosition().y); // Reset to the right
    }
}



void TV::render(sf::RenderWindow& window) {
    tvBody.setScale(0.55, 0.55);
    tvText.setScale(0.55, 0.55);
    screen.setScale(0.55, 0.55);
    leftKnob.setScale(0.55, 0.55);
    rightKnob.setScale(0.55, 0.55);
    antennaBase.setScale(0.55, 0.55);
    antennaLeft.setScale(0.55, 0.55);
    antennaRight.setScale(0.55, 0.55);
    leftLeg.setScale(0.55, 0.55);
    rightLeg.setScale(0.55, 0.55);

    window.draw(antennaBase);
    window.draw(antennaLeft);
    window.draw(antennaRight);
    window.draw(leftLeg);
    window.draw(rightLeg);
    window.draw(tvBody);
    window.draw(screen);
    window.draw(leftKnob);
    window.draw(rightKnob);
    window.draw(tvText);
}


void TV::checkCollision(Studario& studario, Score& score) {
    // Collision::checkCollision(hurdle, studario, score, damageSound, hasCollided, -3);
   Collision::checkCollision(tvBody, studario, score, damageSound, hasCollided, -5);

 
    }
void TV::resetCollisionState() {
    hasCollided = false;  // Reset the collision state
}

sf::FloatRect TV::getBoundingBox() const {
    // Calculate the bounding box for the entire TV, including all parts
    float left = tvBody.getPosition().x;
    float top = tvBody.getPosition().y - 8.f; // Include the antenna height
    float width = tvBody.getSize().x;
    float height = tvBody.getSize().y + 10.f; // Include the legs' height

    return sf::FloatRect(left, top, width, height);
}
void TV::setPosition(float x, float y){
    // Set the TV body position
    tvBody.setPosition(x, y);
    
    // Scale factor
    float scale = 0.55f;

    // Update positions for the other components based on the new TV body position and scale
    screen.setPosition(x + 10.f * scale, y + 7.f * scale); // Positioned inside the TV body
    leftKnob.setPosition(x + 80.f * scale, y + 15.f * scale);
    rightKnob.setPosition(x + 80.f * scale, y + 25.f * scale);
    antennaBase.setPosition(x + 40.f * scale, y - 8.f * scale);
    antennaLeft.setPosition(x + 45.f * scale, y * scale);
    antennaRight.setPosition(x + 45.f * scale, y * scale);
    leftLeg.setPosition(x + 10.f * scale, y + 50.f * scale);
    rightLeg.setPosition(x + 70.f * scale, y + 50.f * scale);
    tvText.setPosition(x + 32.f * scale, y + 15.f * scale);
}


sf::Vector2f TV::getPosition() const {
    return tvBody.getPosition();
}

sf::FloatRect TV::getGlobalBounds() const {
    return tvBody.getGlobalBounds();
}
void TV::stopMovement(){
    velocity = 0;  // Set the velocity to 0 to stop movement
    setPosition(-100.f, tvBody.getPosition().y);
}
void TV::resumeMovement() {
    velocity = 5.0f; // Restore velocity for movement
}