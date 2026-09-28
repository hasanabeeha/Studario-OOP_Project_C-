// #ifndef TV_H
// #define TV_H

// #include <SFML/Graphics.hpp>

// class TV {
// private:
//     // Components of the TV
//     sf::RectangleShape tvBody;
//     sf::RectangleShape screen;
//     sf::RectangleShape leftLeg;
//     sf::RectangleShape rightLeg;
//     sf::CircleShape leftKnob;
//     sf::CircleShape rightKnob;
//     sf::CircleShape antennaBase;
//     sf::RectangleShape antennaLeft;
//     sf::RectangleShape antennaRight;

//     sf::Text tvText;
//     sf::Font font;

// public:
//     // Constructor to initialize all TV components
//     TV();

//     // Render function to draw the TV
//     void render(sf::RenderWindow& window);
//     void update();
// };

// #endif // TV_H

#ifndef TV_H
#define TV_H

#include <SFML/Graphics.hpp>
#include "duedate.h"

class TV : public sf::Drawable
{
private:
    // Components of the TV
    sf::RectangleShape tvBody;
    sf::RectangleShape screen;
    sf::RectangleShape leftLeg;
    sf::RectangleShape rightLeg;
    sf::CircleShape leftKnob;
    sf::CircleShape rightKnob;
    sf::CircleShape antennaBase;
    sf::RectangleShape antennaLeft;
    sf::RectangleShape antennaRight;

    sf::Text tvText;
    sf::Font font;
    // sf::Sound damageSound;
    sf::SoundBuffer damageBuffer; // Sound buffer to hold the sound file
    sf::Sound damageSound;

public:
    // Constructor to initialize all TV components
    TV();

    // Render function to draw the TV
    void render(sf::RenderWindow &window);
    void update();
    void checkCollision(Studario &studario, Score &score);

    sf::Vector2f getPosition() const;
sf::FloatRect getGlobalBounds() const;

    // void resetPosition() {

    // };
    // position = sf::Vector2f(initialX, initialY); // Replace with your logic
    // // isActive = false;                           // Optional: Deactivate

    void resetCollisionState();
    bool hasCollided = false;
    int collisionCount = 0;
    sf::FloatRect getBoundingBox() const;
    void setPosition(float x, float y);
    void stopMovement();
    void resumeMovement();
protected:
    // Override the draw function of sf::Drawable
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        target.draw(tvBody, states);
        target.draw(screen, states);
        target.draw(leftLeg, states);
        target.draw(rightLeg, states);
        target.draw(leftKnob, states);
        target.draw(rightKnob, states);
        target.draw(antennaBase, states);
        target.draw(antennaLeft, states);
        target.draw(antennaRight, states);
        target.draw(tvText, states); // Assuming tvText is also to be rendered
    }
};

#endif // TV_H