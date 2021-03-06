#pragma once

#include "Res.h"

class Player {
	private:
		sf::Sprite sprite;
		sf::Texture texture;

		void InitTexture();
		void InitSprite();

	public:
		void Update();
		void Render(sf::RenderTarget& target);

	public:
		Player();
		virtual ~Player();
};

