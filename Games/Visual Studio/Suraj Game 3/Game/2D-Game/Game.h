#pragma once

#include "Player.h"

class Game {
	private:
		Player* player;

		sf::RenderWindow* window;
		sf::Event ev;

		// Resources
		std::map<std::string, sf::Texture> textures;

		void InitWindow();
		void InitTextures();
		void InitPlayer();

	public:
		void Update();
		void Render();

		void Run();

	public:
		Game();
 		virtual ~Game();
};

