#pragma once

#include "Res.h"

class Player {
	public:
		const bool canAttack();

	private:
		sf::Sprite sprite;
		sf::Texture texture;

		float moveSpeed;

		float attackCooldown;
		float attackCooldownMax;

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
};

