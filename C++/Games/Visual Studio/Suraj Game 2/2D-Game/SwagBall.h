#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

enum SwagBallTypes {
	DEFAULT = 0,
	DEMAGING,
	HEALING,
	NROFTYPES
};

class SwagBall {
	public:

	private:
		sf::CircleShape shape;

		int type;

		void Init(const sf::RenderWindow& window);

	public:
		void Render(sf::RenderTarget* target);
		void Update();


	public: 
		SwagBall(const sf::RenderWindow& windows, int type);
		virtual ~SwagBall();

		const sf::CircleShape getShape() const;
		const int& getType() const;
};

