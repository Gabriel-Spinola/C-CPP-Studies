#pragma once

#include "Res.h"

class Player {
	private:
		sf::Sprite sprite;
		sf::Texture texture;

		float moveSpeed;

		void InitTexture();
		void InitSprite();

		void Move(const short dirX, const short dirY);

	public:
		void Update();
		void Render(sf::RenderTarget& target);

	public:
		Player();
		virtual ~Player();
};

