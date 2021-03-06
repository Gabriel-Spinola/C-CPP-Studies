#pragma once

#include <iostream>

#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class Game {
	private:
		sf::RenderWindow* window;
		sf::Event ev;

		void InitWindow();

	public:
		void Update();
		void Render();

		void Run();

	public:
		Game();
 		virtual ~Game();
};

