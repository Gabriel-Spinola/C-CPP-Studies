#include "Game.h"

void Game::InitWindow() { 
	this->window = new sf::RenderWindow(
		sf::VideoMode(800, 600),
		"Swaglords of Space - Game 3",
		sf::Style::Close | sf::Style::Titlebar
	);
	
	this->window->setFramerateLimit(144);
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
	this->enemy  = new Enemy(20.f, 20.f);
}

void Game::UpdateBullets() { 
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && player->canAttack()) {
		// Add the Bullets to the bullets vector
		bullets.push_back(new Bullet(
			textures["BULLET"],
			player->getPosition().x + 32.f, 
			player->getPosition().y - 14.f,
			0,
			-1,
			5.f
		));
	} 

	unsigned counter = 0;

	for(auto* bullet : bullets) {
		// Update bullets
		bullet->Update();

		// Bullet Culling (top of the screen)
		if(bullet->getBounds().top + bullet->getBounds().height < 0.f) {
			// Delete Bullet
			delete bullets[counter];
			bullets.erase(bullets.begin() + counter);

			--counter;
		}

		++counter;
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

		enemy->Render(window);

		// Render all bullets
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
	delete this->enemy;

	// Delete Textures
	for(auto& i : textures)
		delete i.second;

	// Delete Bullets
	for(auto* i : bullets)
		delete i;
}
