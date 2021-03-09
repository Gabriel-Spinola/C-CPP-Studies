#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
* Class that acts as the game engine
* Wrapper Class.
*/
class Game {
	private:
		/* Private Variables */
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event ev;

		// Mouse Position
		sf::Vector2i mousePosWindow;
		sf::Vector2f mousePosView;

		/* Game Objects */
		// Enemies
		std::vector<sf::RectangleShape> enemies;
		sf::RectangleShape enemy;

		// Resources
		sf::Font font;

		// text
		sf::Text uiText;

		/* Game Logic */
		// Enemies
		bool endGame;
		unsigned points;
		int health;
		int maxEnemies;
		float enemySpawnTimer;
		float enemySpawnTimerMax;

		// Mouse
		bool mouseHeld;
		
		/* Private Functions */
		void InitVariables();
		void InitWindow();
		void InitFonts();
		void InitText();
		void InitEnemies();

	public:
		// Variables
		const int WIDTH = 800;
		const int HEIGHT = 600;

		// Constructors / Destructors
		Game();

		virtual ~Game();

		// Accessors
		const bool Running() const;
		const bool GetEndGame() const;

		// Public Functions
		void UpdateText();
		void RenderText(sf::RenderTarget& target);

		void SpawnEnemy();
		void UpdateEnemies();
		void RenderEnemies(sf::RenderTarget& target);

		void PollEvents();
		void UpdateMousePositions();
		void Update();
		void Render();
};