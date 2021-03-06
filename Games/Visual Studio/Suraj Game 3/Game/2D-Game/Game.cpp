#include "Game.h"

void Game::InitWindow() { 
	this->window = new sf::RenderWindow(
		sf::VideoMode(800, 600),
		"Swaglords of Space - Game 3",
		sf::Style::Close | sf::Style::Titlebar
	);
}

void Game::Update() { 
	window->clear();

		
		
	window->display();
}

void Game::Render() { 
	
}

void Game::Run() {
	while(window->isOpen()) {
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
