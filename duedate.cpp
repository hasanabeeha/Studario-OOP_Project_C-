
// #include "duedate.h"
// #include <iostream>

// DueDate::DueDate(float x, float y, float speed=2.5f) : speed(speed) {
//     // Load the font for the text
//     if (!font.loadFromFile("fonts/arial.ttf")) {
//         std::cerr << "Failed to load font!" << std::endl;
//     }
//     if (!damageBuffer.loadFromFile("damage.wav")) { 
//     std::cerr << "Failed to load damage sound!" << std::endl;
//     }
//     damageSound.setBuffer(damageBuffer);

//     // Set up the rectangle shape for the hurdle
//     hurdle.setSize(sf::Vector2f(80, 40)); // Small rectangle size
//     hurdle.setFillColor(sf::Color::Red);   // Red color for the hurdle
//     hurdle.setPosition(x, y);              // Initial position

//     // Set up the text
//     dueText.setFont(font);
//     dueText.setString("Due Date");
//     dueText.setCharacterSize(15);
//     dueText.setFillColor(sf::Color::White);
//     dueText.setPosition(x + 10, y + 10); // Center the text inside the rectangle

//     initialX=x;
//     initialY=y;
// }

// void DueDate::update() {
//     // Move the hurdle towards the left (negative x direction)


//     if (hasCollided==false)
//     {
//         hurdle.move(-speed, 0);
//     }

//       // Move the text along with the rectangle to keep it centered
//     dueText.setPosition(hurdle.getPosition().x + 10, hurdle.getPosition().y + 10);

//     // Reset position if it goes off the left side of the screen
//     if (hurdle.getPosition().x + hurdle.getSize().x < 0) {
//         resetPosition(); // Reset position
//         resetCollisionState(); // Reset collision state after resetting position
//     }
    
    

//     // Move the text along with the rectangle to keep it centered
//     dueText.setPosition(hurdle.getPosition().x + 10, hurdle.getPosition().y + 10);

//     // Reset position if it goes off the left side of the screen
//     if (hurdle.getPosition().x + hurdle.getSize().x < 0) {
//         hurdle.setPosition(800, hurdle.getPosition().y); // Reset to the right side of the screen

//     }
//         // Check if the hurdle has passed the center of the screen and needs to increase speed
//     // if (!hasCollided) {
//     //     // Gradual speed increase as the hurdle moves towards the left
//     //     if (hurdle.getPosition().x < 400) {  // Once the hurdle crosses the center (X position < 400)
//     //         speed += 0.4f; // Gradually increase speed
//     //         if (speed > 5.0f) { // Maximum speed limit
//     //             speed = 5.0f;
//     //         }
//     //     }

//     //     hurdle.move(-speed, 0);  // Move the hurdle towards the left

//     // }



//     // Move the text along with the rectangle to keep it centered
//     dueText.setPosition(hurdle.getPosition().x + 10, hurdle.getPosition().y + 10);

//     // Reset position if it goes off the left side of the screen
//     if (hurdle.getPosition().x + hurdle.getSize().x < 0) {
//         resetPosition();  // Reset position
//         resetCollisionState();  // Reset collision state after resetting position
//     }

// }
// void DueDate::resetPosition() {
//     // Reset to the initial position
//     hurdle.setPosition(initialX, initialY);
//     dueText.setPosition(initialX + 10, initialY + 10); // Adjust the text position as well
// }
// // void DueDate::getBounds() const {
// //     return hurdle.getGlobalBounds();
// // }

// void DueDate::render(sf::RenderWindow& window) {
//     window.draw(hurdle);      // Draw the rectangle
//     window.draw(dueText);     // Draw the text
// }

// sf::RectangleShape& DueDate::getShape() {
//     return hurdle;            // Access the hurdle shape for collision detection
// }

// void DueDate::checkCollision(Studario& studario,Score& score,Lives& lives) {
//     // Check if the bounding boxes of Studario and DueDate obstacle intersect
//     if (hurdle.getGlobalBounds().intersects(studario.getShape().getGlobalBounds()) && !hasCollided) {
//         std::cout << "Collision with Due Date!" << std::endl;
//         damageSound.stop(); // Stop any previous sound
//         damageSound.play(); // Play the sound
//         hasCollided = true;
//         score.updateScore(-3);

//         // If the score is less than 5, reset it to 0
//         if (score.getScore() < 3) {
//             score.updateScore(-score.getScore()); // Reset the score to 0
//         }

//         int currentLives = lives.getRemainingLives();
//         currentLives--;
//         lives.update(currentLives);
//          std::cout << "Collision detected! Lives remaining: " << lives.getRemainingLives() << std::endl;

//         if (currentLives <= 0) {
//             std::cout << "GAME OVER!" << std::endl;
//             // Additional game over logic can go here
//         }
//         // You can also handle score reduction or other logic here
//         // std::cout << "Collision detected! Lives remaining: " << lives.getRemainingLives() << std::endl;



//         // studario.stopMovement(); // Assuming Studario has a stopMovement() method
//     }
// }

// void DueDate::resetCollisionState() {
//     hasCollided = false;  // Reset the collision state
// }


// #include "duedate.h"
// #include <iostream>

// DueDate::DueDate(float x, float y, float speed) : speed(speed) {
//     // Load the font for the text
//     if (!font.loadFromFile("fonts/arial.ttf")) {
//         std::cerr << "Failed to load font!" << std::endl;
//     }
//     if (!damageBuffer.loadFromFile("damage.wav")) {
//     std::cerr << "Failed to load damage sound!" << std::endl;
//     }
//     damageSound.setBuffer(damageBuffer);
//     border.setSize(sf::Vector2f(90, 50)); // Small rectangle size
//     border.setFillColor(sf::Color::White);   // Red color for the hurdle
//     border.setPosition(x-5, y+15);   
//     // Set up the rectangle shape for the hurdle
//     hurdle.setSize(sf::Vector2f(80, 40)); // Small rectangle size
//     hurdle.setFillColor(sf::Color::Red);   // Red color for the hurdle
//     hurdle.setPosition(x, y+20);              // Initial position

//     // Set up the text
//     dueText.setFont(font);
//     dueText.setString("Due Date");
//     dueText.setCharacterSize(15);
//     dueText.setFillColor(sf::Color::White);
//     dueText.setPosition(x + 10, y + 10); // Center the text inside the rectangle

//     initialX=x;
//     initialY=y;
// }

// void DueDate::update() {
//     // Move the hurdle towards the left (negative x direction)
//     if (hasCollided==false)
//     {
//         hurdle.move(-speed*3, 0);
//         border.move(-speed*3, 0);
//     }
//     // Move the text along with the rectangle to keep it centered
//     dueText.setPosition(hurdle.getPosition().x + 10, hurdle.getPosition().y + 10);

//     // Reset position if it goes off the left side of the screen
//     if (hurdle.getPosition().x + hurdle.getSize().x < 0) {
//         hurdle.setPosition(800, hurdle.getPosition().y); // Reset to the right side of the screen
//     }
// }
// void DueDate::resetPosition() {
//     // Reset to the initial position
//     hurdle.setPosition(initialX, initialY);
//     dueText.setPosition(initialX + 10, initialY + 10); // Adjust the text position as well
// }
// // void DueDate::getBounds() const {
// //     return hurdle.getGlobalBounds();
// // }

// void DueDate::render(sf::RenderWindow& window) {
//     window.draw(border);
//     window.draw(hurdle);      // Draw the rectangle
//     window.draw(dueText);     // Draw the text
// }

// sf::RectangleShape& DueDate::getShape() {
//     return border;
//     return hurdle;            // Access the hurdle shape for collision detection

// }

// void DueDate::checkCollision(Studario& studario,Score& score,Lives&live) {
//     // Check if the bounding boxes of Studario and DueDate obstacle intersect
//     if (hurdle.getGlobalBounds().intersects(studario.getShape().getGlobalBounds()) && !hasCollided) {
//         std::cout << "Collision with Due Date!" << std::endl;
//         damageSound.stop(); // Stop any previous sound
//         damageSound.play(); // Play the sound
//         hasCollided = true;
//         score.updateScore(-3);

//         // If the score is less than 5, reset it to 0
//         if (score.getScore() < 5) {
//             score.updateScore(-score.getScore()); // Reset the score to 0
//         }

//         int currentLives = live.getRemainingLives();
//         currentLives--;
//         live.update(-1);

//          std::cout << "Collision detected! Lives remaining: " << live.getRemainingLives() << std::endl;

//         // studario.stopMovement(); // Assuming Studario has a stopMovement() method
//     }
// }

// void DueDate::resetCollisionState() {
//     hasCollided = false;  // Reset the collision state
// }

#include "duedate.h"
#include <iostream>
DueDate::DueDate(float x, float y, float speed) : speed(speed) {
    // Load the font for the text
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }
    if (!damageBuffer.loadFromFile("damage.wav")) {
    std::cerr << "Failed to load damage sound!" << std::endl;
    }
    damageSound.setBuffer(damageBuffer);
     
    // Set up the rectangle shape for the hurdle
    hurdle.setSize(sf::Vector2f(80, 40)); // Small rectangle size
    hurdle.setFillColor(sf::Color::Red);   // Red color for the hurdle
    hurdle.setPosition(x+5, y+35);              // Initial position
    hurdle.setOutlineThickness(5);
    hurdle.setOutlineColor(sf::Color::White);

    // Set up the text
    dueText.setFont(font);
    dueText.setString("Due Date");
    dueText.setCharacterSize(16);
    dueText.setFillColor(sf::Color::White);
    dueText.setPosition(x , y ); // Center the text inside the rectangle
    dueText.setOutlineThickness(0.5);
    dueText.setOutlineColor(sf::Color::White);
    initialX=x;
    initialY=y;
}

void DueDate::update() {
    // Move the hurdle towards the left (negative x direction)
    // if (hasCollided==false)
    if (collisionCount<300)
    {
        hurdle.move(-speed*9, 0);
    }else
    {
      speed=0;

    }
    

    // Move the text along with the rectangle to keep it centered
    dueText.setPosition(hurdle.getPosition().x +3, hurdle.getPosition().y +5);

    // Reset position if it goes off the left side of the screen
    if (hurdle.getPosition().x + hurdle.getSize().x < 0) {
        hurdle.setPosition(800, hurdle.getPosition().y); // Reset to the right side of the screen
    }
    
}
void DueDate::resetPosition() {
    // Reset to the initial position
    hurdle.setPosition(initialX, initialY+35);
    dueText.setPosition(initialX , initialY ); // Adjust the text position as well
}
// void DueDate::getBounds() const {
//     return hurdle.getGlobalBounds();
// }
void DueDate::setposition(float x, float y){
    resetPosition();
}
void DueDate::render(sf::RenderWindow& window) {
    hurdle.setScale(0.55, 0.55);
    window.draw(hurdle);      // Draw the rectangle
    dueText.setScale(0.55, 0.55);
    window.draw(dueText);     // Draw the text
}

sf::RectangleShape& DueDate::getShape() {
    return hurdle;            // Access the hurdle shape for collision detection
    
}
void DueDate::checkCollision(Studario& studario, Score& score) {
    // Collision::checkCollision(hurdle, studario, score, damageSound, hasCollided, -3);
    Collision::checkCollision(hurdle, studario, score, damageSound, hasCollided, -3) ;
 
    }
void DueDate::resetCollisionState() {
    hasCollided = false;  // Reset the collision state
}


sf::Vector2f DueDate::getPosition() const {
    return hurdle.getPosition();
}

sf::FloatRect DueDate::getGlobalBounds()  {
    return hurdle.getGlobalBounds();
}

void DueDate::setPosition(float x, float y) {
    hurdle.setPosition(x + 5, y + 35);
    dueText.setPosition(x, y);
}
void DueDate::stopMovement(){
    speed = 0; // Stop any further movement by setting speed to 0
    hurdle.setPosition(-200, hurdle.getPosition().y); // Move hurdle outside the screen (to the left)
    dueText.setPosition(-200, dueText.getPosition().y);
}
void DueDate::resumeMovement() {
    if (hasCollided) {
        // Reset the collision state and resume movement
        hasCollided = false;
        speed = 5.0f;

        // If the hurdle is off-screen, reset its position to the initial position
        if (hurdle.getPosition().x < 0) {
            resetPosition(); // Reset to the initial position
        }
    }
}