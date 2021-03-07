#ifndef ENEMY_H
	#define ENEMY_H

	#include <iostream>

	#include "SFML/Graphics.hpp"

class Enemy {
	private:
		sf::CircleShape shape;

		int type;
		int hp;
		int hpMax;
		int damage;
		int points;

	public:
		void Update();
		void Render(sf::RenderTarget& target);

	public:
		Enemy(float posX, float posY);
		virtual ~Enemy();
};
#endif // ! ENEMY_H