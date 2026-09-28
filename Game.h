
// #pragma once
// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
// #include "Studario.h"
// #include "duedate.h"
// #include "lives.h"
// #include "tv.h"
// #include "coin.h"
// class Game {
// public:
//     Game();
//     void run();
//     void updateScore(int increment);

// private:
//     void processEvents();
//     void update();
//     void render();
//     void loadStartScreen();

//     // sf::RenderWindow window;
//     // sf::Font font;
//     // sf::Text titleText;
//     // sf::Text instructionText;

//     sf::RenderWindow window; 
//     sf::Font font; 
//     sf::Text titleText; 
//     sf::Text instructionText; 
//     sf::Texture cloudTexture; 
//     sf::RectangleShape grass; 
//     sf::Sprite cloudSprite;


//     sf::CircleShape cloud1;
//     sf::CircleShape cloud2;
//     sf::CircleShape cloud3;
//     sf::CircleShape cloud4;
//     sf::CircleShape cloud5;
//     Studario studario;
//     bool gameStarted;
//     sf::Text scoreText;  // Text object for displaying score
//     int score; 
//     Coin coinF;
//     TV tv;
//       std::vector<sf::Drawable*> gameObjects; // Vector to store the random objects
//     sf::Drawable* currentGameObject; // Currently active object
//     float timeToNextObject;

   

// };





#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>
#include "Studario.h"
#include "duedate.h"
#include "lives.h"
#include "coin.h"
#include "collision.h"
#include "tv.h"
#include "degree.h"
#include "gameover.h"
#include "promotion.h"
#include <sstream> // For std::ostringstream
#include <iomanip>

class Game {
public:
    Game();
    void run();
    void updateScore(int increment);
    
private:
    void processEvents();
    void update();
    void render();
    void loadStartScreen();
    float calculateGPA();
    // sf::RenderWindow window;
    // sf::Font font;
    // sf::Text titleText;
    // sf::Text instructionText;
    bool gameWon; 
    sf::RenderWindow window; 
    sf::Font font; 
    sf::Text titleText; 
    sf::Text instructionText; 
    sf::Texture cloudTexture; 
    sf::RectangleShape grass; 
    sf::Sprite cloudSprite;


    sf::CircleShape cloud1;
    sf::CircleShape cloud2;
    sf::CircleShape cloud3;
    sf::CircleShape cloud4;
    sf::CircleShape cloud5;
    Studario studario;
    bool gameStarted;
    sf::Text scoreText;  // Text object for displaying score
    int score; 
    Coin coinF;
    GameOverScreen gameover;
    
    TV tv;
    std::vector<sf::Drawable*> gameObjects; // Vector to store the random objects
    sf::Drawable* currentGameObject; // Currently active object
    float timeToNextObject;
   

};