#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class Player {
	public:
		void TakeDamage(const int damage);
		void Heal(const int health);
		const bool Die() const;

	private:
		sf::RectangleShape shape;

		bool leftKey, rightKey, upKey, downKey;

		int hpMax = 10, hp = hpMax;

		float moveSpeed = 10.f;

		void Input();
		void WindowBoundsCollision(const sf::RenderTarget* target);
		void Movement(const sf::RenderTarget* target);

		void Init(float x, float y);

	public:
		void Render(sf::RenderTarget* target);
		void Update(sf::RenderTarget* target);

	public:
		Player(float x = 400.f, float y = 300.f);
		virtual ~Player();

		const sf::RectangleShape& getShape() const;
		const int& getHp() const;
		const int& getHpMax() const;
};

