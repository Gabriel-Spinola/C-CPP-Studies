#include "SwagBall.h"

// Init, Render and Update
void SwagBall::Init(const sf::RenderWindow& window) {
	this->shape.setRadius(static_cast<float>(rand() % 15 + 15));

	sf::Color color;

	switch(this->type) {	
		case DEFAULT:
			color = sf::Color(rand() % 10 + 1, rand() % 100 + 1, rand() % 255 + 1);
		break;

		case DEMAGING:
			color = sf::Color(rand() % 255 + 1, rand() % 20 + 1, rand() % 20 + 1);
		break;
		
		case HEALING:
			color = sf::Color(0, rand() % 255 + 1, rand() % 100 + 1);
		break;
	}
	
	this->shape.setFillColor(color);

	this->shape.setPosition(sf::Vector2f(
		static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
		static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)
	));
}

void SwagBall::Render(sf::RenderTarget* target) {
	target->draw(this->shape);
}

void SwagBall::Update() { 
	
}

// Constructor and Destructor
SwagBall::SwagBall(const sf::RenderWindow& window, int type) : type(type) {
	Init(window);
}

SwagBall::~SwagBall() { }

// Getters and Setters
const sf::CircleShape SwagBall::getShape() const { return this->shape; }
const int& SwagBall::getType() const { return this->type; }
	