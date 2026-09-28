#include "Game.h"
#include <iostream>
DueDate dueDateHurdle(800, 450, 0.05f);
Degree degree(800, 400, 0.5f, "degree.png");
Promotion promotion(800, 400, 0.5f, "promotion.png");
sf::Clock gameclock;
sf::RenderWindow window(sf::VideoMode(800, 600), "Background Sprite Example");
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;
sf::Texture grassTexture;
sf::Sprite grasssprite;
sf::Texture secondBackgroundTexture;
sf::Sprite secondBackgroundSprite;
sf::Texture gamewinTexture;
sf::Sprite gamewinSprite;
sf::Texture startTexture;
sf::Sprite startsprite;
Game::Game() : gameWon(false), window(sf::VideoMode(800, 600), "studario - Start Screen"), studario(100.0f, 980.0f), gameStarted(false), score(0), coinF(0.05f, 600.0f, 470.0f), tv(),
               timeToNextObject(0)
{

    if (!backgroundTexture.loadFromFile("C:/SFML-Progs/Free-Sky-with-Clouds-Background-Pixel-Art6.png"))
    {
        std::cout << "failed to load backgroundpng";
    }

    backgroundSprite.setTexture((backgroundTexture));
    if (!secondBackgroundTexture.loadFromFile("C:/SFML-Progs/Free-Sky-with-Clouds-Background-Pixel-Art8.png"))
    {
        std::cerr << "Failed to load second background image!" << std::endl;
    }
    secondBackgroundSprite.setTexture(secondBackgroundTexture);
    if (!startTexture.loadFromFile("startscreen.png"))
    {
        std::cout << "failed to load startscreenpng";
    }

    startsprite.setTexture((startTexture));
    if (!gamewinTexture.loadFromFile("gamewin.png"))
    {
        std::cerr << "Failed to load second gamewin image!" << std::endl;
    }
    gamewinSprite.setTexture(gamewinTexture);
    if (!grassTexture.loadFromFile("tilesetgrass.png"))
    {
        std::cerr << "Error: Could not load grass texture!" << std::endl;
    }
    grasssprite.setScale(12, 4);
    grasssprite.setTexture(grassTexture);
    grasssprite.setTextureRect(sf::IntRect(0, 96, 74, 32));
    grasssprite.setPosition(-70, 500);

    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
    }
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    // Initialize grass
    grass.setSize(sf::Vector2f(800, 100));
    grass.setFillColor(sf::Color(34, 139, 34)); // Green color for grass
    grass.setPosition(0, 500);

    // Title Text
    titleText.setFont(font);
    titleText.setString("STUDARIO");
    titleText.setCharacterSize(50);
    titleText.setFillColor(sf::Color::Red);
    titleText.setPosition(250, 200);
    titleText.setOutlineThickness(3);
    titleText.setOutlineColor(sf::Color::White);

    // Instruction Text
    instructionText.setFont(font);
    instructionText.setString("Press Space bar to Continue");
    instructionText.setCharacterSize(20);
    instructionText.setFillColor(sf::Color::Black);
    instructionText.setPosition(250, 300);

    // Initialize cloud components (circles)
    cloud1.setRadius(40);
    cloud1.setFillColor(sf::Color(255, 255, 255)); // White for cloud
    cloud1.setPosition(100, 100);                  // Initial position of cloud

    cloud2.setRadius(50);
    cloud2.setFillColor(sf::Color(255, 255, 255));
    cloud2.setPosition(130, 90);

    cloud3.setRadius(45);
    cloud3.setFillColor(sf::Color(255, 255, 255));
    cloud3.setPosition(60, 110);

    cloud4.setRadius(40);
    cloud4.setFillColor(sf::Color(255, 255, 255));
    cloud4.setPosition(140, 120);

    cloud5.setRadius(35);
    cloud5.setFillColor(sf::Color(255, 255, 255));
    cloud5.setPosition(180, 100);

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 10);
    gameObjects.push_back(&dueDateHurdle);
    gameObjects.push_back(&tv);
    gameObjects.push_back(&coinF);
    // gameObjects.push_back(&degreeSprite);

    currentGameObject = &dueDateHurdle;
}

void Game::run()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        processEvents();
        sf::Time deltaTime = gameclock.restart();
        float deltaSeconds = deltaTime.asSeconds();
        studario.update(deltaSeconds);
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                studario.jump(); // Trigger the jump
            }
            if (event.key.code == sf::Keyboard::Space)
            {
                gameStarted = true;
                std::cout << "Game Started!" << std::endl;
            }
        }
    }
}

void Game::updateScore(int increment)
{
    score += increment;
    scoreText.setString("Score: " + std::to_string(score)); // Update score display
}

Score scoref("fonts/arial.ttf", 10.0f, 10.0f);
Lives live("fonts/arial.ttf", 10.0f, 10.0f);

void Game::update()
{
    if (scoref.currentscore() >= 150 || promotion.hasCollided)
    {
        gameWon = true;
        gameStarted = false;
    }
    if (Collision::collisionCount == 3)
    {
        float gpa = calculateGPA();
        gameover.loadTexture("over.png");
        gameover.render(window);

        sf::Text gpaText;
        gpaText.setFont(font);
        gpaText.setCharacterSize(24);
        gpaText.setFillColor(sf::Color::White);
        gpaText.setOutlineThickness(2);
        gpaText.setOutlineColor(sf::Color::Black);
        gpaText.setPosition(300, 550);

        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << gpa;
        gpaText.setString("Your GPA: " + oss.str());
        window.draw(gpaText);
        window.display();

        sf::sleep(sf::seconds(5));
        window.close();
    }
    if (score >= 70 && backgroundSprite.getTexture() != &secondBackgroundTexture)
    {
        backgroundSprite.setTexture(secondBackgroundTexture); // Switch to new background
    }
    float deltaTime = gameclock.restart().asSeconds();
    // studario.setJumpHeightAndDuration(200.0f, 1.0f);
    studario.update(deltaTime);
    // Move the cloud across the screen
    cloud1.move(0.05f, 0); // Adjust the speed of cloud movement
    cloud2.move(0.05f, 0);
    cloud3.move(0.05f, 0);
    cloud4.move(0.05f, 0);
    cloud5.move(0.05f, 0);

    if (cloud1.getPosition().x > 800)
    {
        cloud1.setPosition(-cloud1.getLocalBounds().width, cloud1.getPosition().y); // Reset position when cloud goes off-screen
        cloud2.setPosition(cloud1.getPosition().x + 30, cloud2.getPosition().y);
        cloud3.setPosition(cloud1.getPosition().x + 50, cloud3.getPosition().y);
        cloud4.setPosition(cloud1.getPosition().x - 80, cloud4.getPosition().y);
        cloud5.setPosition(cloud1.getPosition().x - 120, cloud5.getPosition().y);
    }
    if (gameStarted)
    {
        if (currentGameObject == nullptr ||
            // Check for sf::Sprite object (like Coin)
            (dynamic_cast<sf::Sprite *>(currentGameObject) &&
             dynamic_cast<sf::Sprite *>(currentGameObject)->getPosition().x + dynamic_cast<sf::Sprite *>(currentGameObject)->getGlobalBounds().width < 0) ||
            // Check for sf::RectangleShape object (like TV)
            (dynamic_cast<sf::RectangleShape *>(currentGameObject) &&
             dynamic_cast<sf::RectangleShape *>(currentGameObject)->getPosition().x + dynamic_cast<sf::RectangleShape *>(currentGameObject)->getGlobalBounds().width < 0) ||
            // Check for DueDate object (assuming it has getPosition() and getBounds())
            (dynamic_cast<DueDate *>(currentGameObject) &&
             dynamic_cast<DueDate *>(currentGameObject)->getPosition().x + dynamic_cast<DueDate *>(currentGameObject)->getGlobalBounds().width < 0) ||
            // Check for TV object (assuming it has getPosition() and getBounds())
            (dynamic_cast<TV *>(currentGameObject) &&
             dynamic_cast<TV *>(currentGameObject)->getPosition().x + dynamic_cast<TV *>(currentGameObject)->getGlobalBounds().width < 0))
        {
            // Pick a new random object when the current one goes off-screen
            int randomIndex = std::rand() % 3;
            currentGameObject = gameObjects[randomIndex];
            if (currentGameObject == &dueDateHurdle)
            {
                dueDateHurdle.setPosition(800, 450); // Reset position for re-use
            }
            else if (currentGameObject == &tv)
            {
                tv.setPosition(800, 480);
            }
            else if (currentGameObject == &coinF)
            {
                coinF.setPosition(800, 470);
            }
            // }else if (currentGameObject == &degreeSprite) {
            //     coinF.setPosition(800, 460);
            // }
        }
        if (currentGameObject == &dueDateHurdle)
        {
            dueDateHurdle.update();
            dueDateHurdle.checkCollision(studario, scoref);
            dueDateHurdle.render(window);
            if (dueDateHurdle.getPosition().x + dueDateHurdle.getGlobalBounds().width < 0)
            {
                currentGameObject = nullptr;
                // Reset current game object
                std::cout << "Current object duedate is set to null pointer" << std::endl;
            }
        }
        else if (currentGameObject == &tv)
        {
            tv.update();
            tv.checkCollision(studario, scoref);
            tv.render(window);
            if (tv.getPosition().x + tv.getGlobalBounds().width < 0)
            {
                currentGameObject = nullptr;
                std::cout << "Current object tv is set to null pointer" << std::endl;
            }
        }
        else if (currentGameObject == &coinF)
        {

            coinF.update(deltaTime, scoref);
            coinF.checkCollision(studario, scoref);
            coinF.render(window);
            if (coinF.getPosition().x <= 40.0f)
            {
                currentGameObject = nullptr;
                std::cout << "Current object coin is set to null pointer" << std::endl;
            }
        }
        // else if (currentGameObject == &degreeSprite)
        // {
        //     degreeSprite.update();
        //     degreeSprite.render(window);
        //     if (degreeSprite.getPosition().x < 50.0f) {
        //         currentGameObject = nullptr;
        //         std::cout<<"Current object degree is set to null pointer"<<std::endl;
        //     }
        // }
        if (Collision::collisionCount == 3)
        {
            gameover.loadTexture("over.png");
            gameover.render(window);
            gameStarted = false;
        }
    }
    // Update score and lives
    scoref.update(window);
    live.update(3); // Adjust accordingly
    // degree.update();
    // degree.checkCollision(studario, scoref);
    studario.updateCharacter(scoref.getScore());
}
float Game::calculateGPA()
{
    float maxScore = 150.0f;                          // Maximum possible score
    return (scoref.currentscore() / maxScore) * 4.0f; // GPA on a 4.0 scale
}
void Game::render()
{
    window.clear(sf::Color(135, 206, 235)); // Sky blue color
    if (scoref.currentscore() < 70)
    {
        window.draw(backgroundSprite);
        backgroundSprite.setPosition(-40, -120);
    }
    else
    {
        window.draw(secondBackgroundSprite);
        secondBackgroundSprite.setPosition(-40, -120);
    } // grasssprite.setPosition(300, 100);
    // Draw background elements
    window.draw(grass);
    window.draw(grasssprite);
    // Draw clouds
    window.draw(cloud1);
    window.draw(cloud2);
    window.draw(cloud3);
    window.draw(cloud4);
    window.draw(cloud5);

    // Draw each part of Studario

    if (!gameStarted)
    {
        // window.draw(backgroundSprite);
        startsprite.setPosition(-40, 10);
        window.draw(startsprite);
        window.draw(titleText);
        window.draw(instructionText);
        window.draw(startsprite);
    }
    window.draw(studario.getSprite());

    // Draw title and instruction text
    if (currentGameObject)
    {
        window.draw(*currentGameObject);
    }
    // dueDateHurdle.render(window);
    live.draw(window);
    window.draw(scoreText);
    scoref.draw(window);
    gameover.render(window);
    // tv.render(window);
    // coinF.render(window);
    sf::Text modeText;
    modeText.setFont(font);
    modeText.setCharacterSize(26);
    modeText.setFillColor(sf::Color::Black);
    modeText.setOutlineThickness(2);
    modeText.setOutlineColor(sf::Color::White);
    modeText.setPosition(290, 5); // Top middle position

    if (scoref.currentscore() < 70)
    {
        modeText.setString("STUDENT MODE");
    }
    else
    {
        modeText.setString("EMPLOYEE MODE");
    }
    window.draw(modeText);
    if (scoref.currentscore() >= 40 && scoref.currentscore() <= 70)
    {
        // degree.render(window);
        degree.update();
        degree.checkCollision(scoref, studario);
        degree.render(window);
    }

    if (scoref.currentscore() >= 110 && scoref.currentscore() <= 150)
    {
        // degree.render(window);
        promotion.update();
        promotion.checkCollision(scoref, studario);
        promotion.render(window);
    }
    if (gameWon)
    {
        // Draw gamewin screen
        window.draw(gamewinSprite);
        gamewinSprite.setPosition(0, 0); // Adjust position if necessary
        window.display();

        sf::sleep(sf::seconds(5)); // Pause for 5 seconds
        window.close();
        return; // Exit render early since the game is over
    }
    // Display everything on the screen
    window.display();
}

int main()
{
    Game game;
    game.run();

    return 0;
}