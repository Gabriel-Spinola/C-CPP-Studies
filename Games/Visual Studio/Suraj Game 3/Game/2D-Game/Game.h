#ifndef GAME_H
	#define GAME_H

	#include <iostream>
	#include <map>

	#include "SFML/System.hpp"
	#include "SFML/Graphics.hpp"
	#include "SFML/Window.hpp"
	
	#include "Player.h"
	#include "Bullet.h"
	#include "Enemy.h"

class Game {
	private:
		Player* player;

		std::vector<Bullet*> bullets;
		std::vector<Enemy*> enemies;

		sf::RenderWindow* window;
		sf::Event ev;

		float spawnTimerMax;
		float spawnTimer;

		void InitWindow();
		void InitTextures();

		void UpdateBullets();
		void UpdateEnemies();

	private:
		// Resources
		std::map<std::string, sf::Texture*> textures;

	public:
		void Update();
		void Render();

		void Run();

	public:
		Game();
 		virtual ~Game();
};
#endif // ! GAME_H