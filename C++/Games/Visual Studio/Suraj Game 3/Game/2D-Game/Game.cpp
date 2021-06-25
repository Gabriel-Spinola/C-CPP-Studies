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

void Game::InitGUI() { 
	if(!this->font.loadFromFile("Fonts/Metropolian-Display.ttf")) {
		std::cout << "Can't load GUI Font" << std::endl;
	}

	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(12);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("Test");
}

void Game::UpdateGUI() { 
	
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

	if(!bullets.empty()) {
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
}

void Game::UpdateEnemies() { 
	// Spawning
	spawnTimer += 0.8f;

	if(spawnTimer >= spawnTimerMax) {
		// Add enemy to the enemies vector (Basically spawning them) 
		enemies.push_back(new Enemy(
			static_cast<float>( rand() % window->getSize().x - 45 ),
			0.f
		));

		spawnTimer = 0.f;
	}

	// Update
	if(!enemies.empty()) {
		unsigned counter = 0;

		for(auto* enemy : enemies) {
			// Update bullets
			enemy->Update();

			// Bullet Culling (top of the screen)
			if(enemy->getBounds().top > window->getSize().y) {
				// Delete Bullet
				delete enemies[counter];
				enemies.erase(enemies.begin() + counter);

				--counter;
			}

			++counter;
		}
	}
}

void Game::UpdateCombat() { 
	// isEnemyDeleted it's used to prevent looping a deleted enemy or bullet
	for(int i = 0; i < enemies.size(); i++) {
		bool isEnemyDeleted = false;

		for(int j = 0; j < bullets.size() && !isEnemyDeleted; j++) {
			if(enemies[i]->getBounds().intersects(bullets[j]->getBounds())) {
				delete enemies[i];
				enemies.erase(enemies.begin() + i);
				
				delete bullets[j];
				bullets.erase(bullets.begin() + j);

				isEnemyDeleted = true;
			}
		}
	}
}

void Game::Update() { 
	player->Update();

	UpdateBullets();
	UpdateEnemies();
	UpdateCombat();
	UpdateGUI();
}


void Game::Render() { 
	window->clear();
		
		// Render Player
		player->Render(*window);

		window->draw(pointText);

		// Render all Enemy
		for(auto* enemy : enemies) {
			enemy->Render(*window);
		}

		// Render all bullets
		for(auto* enemy : bullets) {
			enemy->Render(*window);
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
	this->InitGUI();

	this->player = new Player();

	this->spawnTimerMax = 40.f;
	this->spawnTimer = this->spawnTimerMax;
}

Game::~Game() { 
	delete this->window;
	delete this->player;

	// Delete Textures
	for(auto& texture : this->textures)
		delete texture.second;

	// Delete Bullets
	for(auto* bullet : this->bullets)
		delete bullet;
	
	// Delete Enemies
	for(auto* enemy : this->enemies)
		delete enemy;
}
