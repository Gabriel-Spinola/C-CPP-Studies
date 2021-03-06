#pragma once

#include "Res.h"

class Player {
	private:
		sf::Sprite sprite;
		sf::Texture texture;

		float moveSpeed;

		void InitTexture();
		void InitSprite();

		void Move(const int dirX, const int dirY);
		void Movement();

	public:
		void Update();
		void Render(sf::RenderTarget& target);

	public:
		Player();
		virtual ~Player();
};

