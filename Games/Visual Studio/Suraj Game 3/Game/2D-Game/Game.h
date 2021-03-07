#ifndef GAME_H
	#define GAME_H

	#include "Player.h"
	#include "Bullet.h"

class Game {
	private:
		Player* player;

		sf::RenderWindow* window;
		sf::Event ev;

		void InitWindow();
		void InitTextures();
		void InitPlayer();

		void UpdateBullets();

	private:
		// Resources
		std::map<std::string, sf::Texture*> textures;

		std::vector<Bullet*> bullets;

	public:
		void Update();
		void Render();

		void Run();

	public:
		Game();
 		virtual ~Game();
};
#endif // ! GAME_H