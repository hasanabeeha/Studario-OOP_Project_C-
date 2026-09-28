#ifndef COLLISION_H
#define COLLISION_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Studario.h"
#include "score.h"
#include "lives.h"
class Collision
{

public:
    Collision();
    static void checkCollision(sf::RectangleShape &obstacle, Studario &studario, Score &score, sf::Sound &collisionSound, bool &hasCollided, int scorePenalty);
    static void checkCollision(sf::Sprite &obstacle, Studario &studario, Score &score, sf::Sound &collisionSound, bool &hasCollided, int scorePenalty);
    static int collisionCount;
};
#endif // COLLISION_H