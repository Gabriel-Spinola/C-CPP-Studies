#ifndef PLAYER_H
	#define PLAYER_H

	#include <iostream>
	
	#include "SFML/System.hpp"
	#include "SFML/Graphics.hpp"

class Player {
	public:
		const bool canAttack();

	private:
		sf::Sprite sprite;
		sf::Texture texture;

		float moveSpeed;

		float attackCooldown;
		float attackCooldownMax;

		int hpMax;
		int hp;

		void InitTexture();
		void InitSprite();

		void Move(const int dirX, const int dirY);
		void Movement();

		void Cooldown();

	public:
		void Update();
		void Render(sf::RenderTarget& target);

	public:
		Player();
		virtual ~Player();

		const sf::Vector2f& getPosition() const;
		const sf::FloatRect getBounds() const;

		const int& getHP() const;
		const int& getHPMax() const;

		void setPosition(const sf::Vector2f pos);
		void setPosition(const float x, const float y);

		void setHP(const int hp);
		void loseHp(const int damage);
};

#endif // ! PLAYER_H