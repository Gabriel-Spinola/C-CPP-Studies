#pragma once

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

#include "Player.h"
#include "SwagBall.h"

class Game {
	public:
		const bool IsRunning() const;

		void PollEvents();

	private:
		Player player;
		
		std::vector<SwagBall> swagBalls;

		float spawnTimerMax;
		float spawnTimer;
		int maxSwagBalls;

		int points;

		sf::Font font;
		sf::Text guiText;

		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event ev;

		bool endGame;

		const int RandomizeType() const;
		void SpawnSwagBalls();
		void UpdateCollision();

		void InitWindow();
		void InitGuiFontAndText();

		void RenderGui(sf::RenderTarget* target);

		void UpdateGui();

		void Init();

	public:
		void Render();
		void Update();

	public:
		Game();
		~Game();

		const bool& getEndGame() const;
};