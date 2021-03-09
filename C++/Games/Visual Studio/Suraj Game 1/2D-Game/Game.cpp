#include "Game.h"

#pragma region Private Functions

/*
* @return void
* 
* Init private Variables
*/
void Game::InitVariables() {
	window = nullptr;

    // Game Logic 
    points = 0;
    health = 10;
    maxEnemies = 5;
    enemySpawnTimer = 0.f;
    enemySpawnTimerMax = 15.f;

    mouseHeld = false;

    endGame = false;
}

/*
* @return void
* 
* - Set Window Variables
* - Create Window
* - Set Frame Rate Limit
*/
void Game::InitWindow() {
	// Set window width and height
	videoMode.width = WIDTH;
	videoMode.height = HEIGHT;

	// Create window with 640x480px, with a title bar and a close window option.
	window = new sf::RenderWindow(videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);
}

void Game::InitFonts() {
    if(!font.loadFromFile("Fonts/DancingScript-Bold.tff")) {
        std::cout << "ERROR::GAME::InitFonts::Failed to load font!" << "\n";
    }
}

void Game::InitText() { 
    uiText.setFont(font);
    uiText.setFillColor(sf::Color::White);
    uiText.setPosition(10.f, 10.f);
    uiText.setCharacterSize(24);
    uiText.setString("NONE");
}

/*
* @return void
* 
* - Set Enemies info (pos, size, scale, color...)
*/
void Game::InitEnemies() {
    // enemy.setPosition(sf::Vector2f(10.f, 10.f));

    enemy.setSize(sf::Vector2f(100.f, 100.f));
    enemy.setScale(sf::Vector2f(0.5f, 0.5f));

    enemy.setFillColor(sf::Color::Red);
}

#pragma endregion

#pragma region Constructors / Destructors

Game::Game() {
	InitVariables();
	InitWindow();

    InitFonts();
    InitText();

    InitEnemies();
}

Game::~Game() {
	delete window;
}

#pragma endregion

#pragma region Accessors

/*
* @return bool const
* 
* - Check if the games is running.
*/
const bool Game::Running() const {
	return window->isOpen();
}

/*
* @return bool const
* 
* - Check end game
*/
const bool Game::GetEndGame() const {
    return endGame;
}

#pragma endregion

#pragma region Public Functions.

void Game::UpdateText() {
    std::stringstream ss;

    ss << "Points: " << points << "\n" << "Health: " << health << "\n";

    uiText.setString(ss.str());
}

void Game::RenderText(sf::RenderTarget& target) {
    target.draw(uiText);
}

/**
 * @return void
 *
 * Spawns enemies and sets their characteristics.
 * - Sets a random position
 * - Set their types and Colors
 * - Adds enemy to the vector
*/
void Game::SpawnEnemy() {
    // Set the enemy's position to a random locations relative to the windows size minus enemy's size.
    enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy.getSize().x)),
        static_cast<float>(rand() % static_cast<int>(window->getSize().y - enemy.getSize().y))
    );

    // Randomize enemy Type
    int type = rand() % 5;

    switch(type) {
        case 0:
            enemy.setFillColor(sf::Color::Magenta);
            enemy.setSize(sf::Vector2f(45.f, 45.f));
        break;

        case 1:
            enemy.setFillColor(sf::Color::Green);
            enemy.setSize(sf::Vector2f(50.f, 50.f));
        break;

        case 2:
            enemy.setFillColor(sf::Color::Blue);
            enemy.setSize(sf::Vector2f(70.f, 70.f));
        break;

        case 3:
            enemy.setFillColor(sf::Color::Red);
            enemy.setSize(sf::Vector2f(60.f, 56.f));
        break;

        default: 
            enemy.setSize(sf::Vector2f(35.f, 35.f));
            enemy.setFillColor(sf::Color::Yellow);
        break;
    }

    // Spawn the enemy
    enemies.push_back(enemy);
}

/*
* @return void
*
* - Updates the enemy spawn timer and spawns enemies when the
*   total amount of enemies is smaller than the maximum.
* - Moves the enemies downward.
* - Remove the enemies at the edge of the screen.
*/
void Game::UpdateEnemies() {
    // Update the timer for enemy spawning.
    if(enemies.size() < maxEnemies) {
        if(enemySpawnTimer >= enemySpawnTimerMax) {
            // Spawn the enemy and reset the timer.
            SpawnEnemy();
            enemySpawnTimer = 0.f;
        }
        else
            enemySpawnTimer += 1.f;
    }

    // Moving and updating enemies.
    for(int i = 0; i < enemies.size(); i++) {
        bool deleted = false;

        enemies[i].move(0.f, 1.f);

        // if the enemy is past the bottom of the window
        if(enemies[i].getPosition().y > window->getSize().y) {
            enemies.erase(enemies.begin() + i);

            health--;
        }
    }

    // Check if clicked upon
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if(!mouseHeld) {
            mouseHeld = true;
            bool deleted = false;

            for(int i = 0; i < enemies.size() && !deleted; i++) {
                if(enemies[i].getGlobalBounds().contains(mousePosView)) {
                    // Gain points
                    if(enemies[i].getFillColor() == sf::Color::Magenta)
                        points += 10;
                    else if(enemies[i].getFillColor() == sf::Color::Yellow)
                        points += 20;
                    else if(enemies[i].getFillColor() == sf::Color::Green)
                        points += 5;
                    else
                        points++;

                    // Delete the enemy.
                    deleted = true;
                    enemies.erase(enemies.begin() + i);
                }
            }
        }
    }
    else {
        mouseHeld = false;
    }

    std::cout << "points: " << points << " health: " << health << "\n";
}

/*
* @return void
* 
* Render Enenemies.
*/
void Game::RenderEnemies(sf::RenderTarget& target) {
    // Rendering all the enemies
    for(auto& e : enemies) {
        target.draw(e);
    }
}

/*
* @return void
* 
* - Set window poll events
*/
void Game::PollEvents() {
    // Get window events and put in the "ev" variable
    while(window->pollEvent(ev)) {
        switch(ev.type) {
            case sf::Event::Closed:
                window->close();
            break;

            case sf::Event::KeyPressed:
                if(ev.key.code == sf::Keyboard::Escape)
                    window->close();
            break;
        }
    }
}

/*
* @return void
* 
* Updates the mouse positions 
* - Get Mouse position relative to window (Vector2i)
* - Get Mouse postion relative to view (Vector2f)
*/
void Game::UpdateMousePositions() {
    mousePosWindow = sf::Mouse::getPosition(*window);
    mousePosView = window->mapPixelToCoords(mousePosWindow);
}

/*
* @return void
* 
* Update game
* 
* - Instatiate Update functions
* - Debug logs
*/
void Game::Update() {
    // Update Game Engine
    PollEvents();
    
    if(!endGame) {
        // Update Mouse
        UpdateMousePositions();

        // Update Text
        UpdateText();

        // Update Enemies
        UpdateEnemies();
    }

    // end game condition
    if(health <= 0)
        endGame = true;

    // Update Mouse Position Relative to the window
    // std::cout << "Mouse pos: " << sf::Mouse::getPosition(*window).x << "x  " << sf::Mouse::getPosition(*window).y << "y\n";
} 

/*
* @return void
* 
* Render The Game
* 
* 1. Clear old frams
* 2. Render objects
* 3. Display frames in window
*/
void Game::Render() {
    // 1.
    window->clear();

    // 2.
    RenderEnemies(*window);
    RenderText(*window);

    // 3.
    window->display();
}

#pragma endregion