// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
// #include "Studario.h"
// #include "score.h"
// #include "lives.h"

// class DueDate {
// public:
//     DueDate(float x, float y, float speed); // Constructor with speed parameter

//     void update();                          // Update the position (moving left)
//     void render(sf::RenderWindow& window);  // Draw the hurdle on the window
//     void resetPosition();
//     // void getBounds() const;
//     sf::RectangleShape& getShape();         // Accessor for collision detection
//     void checkCollision(Studario& studario,Score& score,Lives& lives);
//     void resetCollisionState();
//     bool hasCollided=false;  
// private:
//     sf::RectangleShape hurdle;              // Rectangle shape representing the hurdle
//     sf::Text dueText;                       // Text label for "Due Date"
//     sf::Font font;                          // Font for text
//     sf::SoundBuffer damageBuffer;         // Sound buffer to hold the sound file
//     sf::Sound damageSound; 
   
//     float speed;  
//     float initialX;                         // Initial x-position
//     float initialY;     
//                          // Speed of the hurdle moving towards Studario
// };



// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
// #include "Studario.h"
// #include "score.h"
// #include "lives.h"

// class DueDate {
// public:
//     DueDate(float x, float y, float speed); // Constructor with speed parameter

//     void update();                          // Update the position (moving left)
//     void render(sf::RenderWindow& window);  // Draw the hurdle on the window
//     void resetPosition();
//     // void getBounds() const;
//     sf::RectangleShape& getShape();         // Accessor for collision detection
//     void checkCollision(Studario& studario,Score& score,Lives&live);
//     void resetCollisionState();
//     bool hasCollided=false;  
// private:
//     sf::RectangleShape hurdle;              // Rectangle shape representing the hurdle
//     sf::RectangleShape border;
//     sf::Text dueText;                       // Text label for "Due Date"
//     sf::Font font;                          // Font for text
//     sf::SoundBuffer damageBuffer;         // Sound buffer to hold the sound file
//     sf::Sound damageSound; 
   
//     float speed;  
//     float initialX;                         // Initial x-position
//     float initialY;                          // Speed of the hurdle moving towards Studario
    
// };


#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Studario.h"
// #include "score.h"
#include "collision.h"

class DueDate : public sf::Drawable{
public:
    DueDate(float x, float y, float speed); // Constructor with speed parameter

    void update();                          // Update the position (moving left)
    void render(sf::RenderWindow& window); 
     // Draw the hurdle on the window
     void setposition(float x, float y);
    void resetPosition();
    // void getBounds() const;
    sf::RectangleShape& getShape();         // Accessor for collision detection
    void checkCollision(Studario& studario,Score& score);
    void resetCollisionState();
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds()  ;
    void setPosition(float x, float y);
    bool hasCollided=false;  
     int collisionCount = 0;  
    void stopMovement();
    void resumeMovement();
private:
    sf::RectangleShape hurdle;     
    sf::Text dueText;                       // Text label for "Due Date"
    sf::Font font;                          // Font for text
    sf::SoundBuffer damageBuffer;         // Sound buffer to hold the sound file
    sf::Sound damageSound; 
   
    float speed;  
    float initialX;                         // Initial x-position
    float initialY;  
                            // Speed of the hurdle moving towards Studario

protected:
    // Override the draw function of sf::Drawable
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
            target.draw(hurdle, states);
        target.draw(hurdle, states);  // Draw the hurdle shape
      // Draw border if needed
        target.draw(dueText, states);  // Draw the due date text
    }
};