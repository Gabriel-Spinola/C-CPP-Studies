#include "Game.h"

// Public Methods
const bool Game::IsRunning() const {
	return this->window->isOpen() && !this->player.Die();
}

void Game::PollEvents() {
	while(this->window->pollEvent(this->ev)) {
		switch(this->ev.type)
		{
			case sf::Event::Closed:
				this->window->close();
			break;

			case sf::Event::KeyPressed:
				if(this->ev.key.code == sf::Keyboard::Escape)
					this->window->close();
			break;
		}
	}
}

const int Game::RandomizeType() const {
	int type = SwagBallTypes::DEFAULT;
	int randValue = rand() % 100 + 1;

	if(randValue > 60 && randValue <= 90) { 
		type = SwagBallTypes::DEMAGING;
	}
	else if(randValue > 90 && randValue <= 100) {
		type = SwagBallTypes::HEALING;
	}

	return type;
}

// Private Method
void Game::SpawnSwagBalls() { 
	// Timer
	if(this->spawnTimer < this->spawnTimerMax) {
		this->spawnTimer += 1.f;
	}
	else if(this->swagBalls.size() < this->maxSwagBalls) {
		this->swagBalls.push_back(SwagBall(*this->window, RandomizeType()));

		this->spawnTimer = 0.f;
	}
}

void Game::UpdateCollision() {
	for(int i = 0; i < swagBalls.size(); i++) {
		if(
			this->player.getShape().getGlobalBounds().intersects(
				this->swagBalls[i].getShape().getGlobalBounds()
			)
		) {
			switch(this->swagBalls[i].getType()) {
				case SwagBallTypes::DEFAULT:
					this->points++;
				break;

				case SwagBallTypes::DEMAGING:
					player.TakeDamage(1);
				break;

				case SwagBallTypes::HEALING:
					player.Heal(1);
				break;
			}

			this->swagBalls.erase(this->swagBalls.begin() + i);
		}
	}
}

void Game::InitWindow() {
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(videoMode, "Game 2", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::InitGuiFontAndText() {
	if(!this->font.loadFromFile("Fonts/Metropolian-Display.ttf")) {
		std::cout << "! ERROR::GAME::INITFONTS | can't load Metropolian-Display.ttf ):" << std::endl;
	}

	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(20);
}

void Game::RenderGui(sf::RenderTarget* target) {
	target->draw(this->guiText);
}

void Game::UpdateGui() {
	std::stringstream ss;
	
	ss << "Points: " << this->points << std::endl <<
		"Health: " << player.getHp() << " | " <<
		this->player.getHpMax() << std::endl;

	this->guiText.setString(ss.str());
}
	
// Init and Update
void Game::Init() { 
	InitWindow();
	InitGuiFontAndText();

	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 10;

	this->points = 0;

	this->endGame = false;
}

void Game::Render() {
	this->window->clear();
	
	this->player.Render(this->window);

	for(auto i : this->swagBalls) {
		i.Render(this->window);
	}

	this->RenderGui(this->window);

	this->window->display();
}

void Game::Update() { 
	PollEvents();

	player.Update(this->window);

	SpawnSwagBalls();
	UpdateCollision();
	UpdateGui();
}

// Constructors and Destructors
Game::Game() { 
	Init();
}

Game::~Game() { 
	delete this->window;
}

const bool& Game::getEndGame() const { return endGame; }