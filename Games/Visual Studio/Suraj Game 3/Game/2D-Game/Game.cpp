#include "Game.h"

void Game::InitWindow() { 
	this->window = new sf::RenderWindow(
		sf::VideoMode(800, 600),
		"Swaglords of Space - Game 3",
		sf::Style::Close | sf::Style::Titlebar
	);
	
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::Update() { 
	
}

void Game::Render() { 
	window->clear();
	
		player.Render(*window);

	window->display();
}

void Game::Run() {
	while(window->isOpen()) {
		while(window->pollEvent(ev)) {
			switch(ev.type) {
				case sf::Event::Closed:
					this->window->close();
				break;

				case sf::Event::KeyPressed:
					if(ev.key.code == sf::Keyboard::Escape)
						this->window->close();
				break;
			}
		}

		this->Update();
		this->Render();
	}
}

Game::Game() {
	this->InitWindow();
}

Game::~Game() { 
	delete this->window;
}
