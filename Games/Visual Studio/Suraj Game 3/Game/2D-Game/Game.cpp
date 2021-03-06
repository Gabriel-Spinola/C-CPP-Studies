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

void Game::InitTextures() {
	// Set the BULLET position to a new Texture
	this->textures["BULLET"] = new sf::Texture();

	// Set the texture
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
}

void Game::InitPlayer() { 
	this->player = new Player();
}

void Game::UpdateBullets() { 
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		bullets.push_back(new Bullet(
			textures["BULLET"],
			player->getPosition().x, 
			player->getPosition().y,
			0,
			0,
			0.f
		));
	}

	for(auto* i : bullets) {
		i->Update();
	}
}

void Game::Update() { 
	player->Update();
	UpdateBullets();
}

void Game::Render() { 
	window->clear();
		
		// Render player
		player->Render(*window);

		for(auto* i : bullets) {
			i->Render(window);
		}

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
	this->InitTextures();
	this->InitPlayer();
}

Game::~Game() { 
	delete this->window;
	delete this->player;

	// Delete Textures
	for(auto& i : textures) {
		delete i.second;
	}

	// Delete Bullets
	for(auto* i : bullets) {
		delete i;
	}
}
