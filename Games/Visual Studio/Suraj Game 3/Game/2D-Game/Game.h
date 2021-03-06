#pragma once

#include "Player.h"

class Game {
	private:
		Player* player;

		sf::RenderWindow* window;
		sf::Event ev;

		void InitWindow();
		void InitPlayer();

	public:
		void Update();
		void Render();

		void Run();

	public:
		Game();
 		virtual ~Game();
};

