#include "Enemy.h"

void Enemy::Update() { 

}

void Enemy::Render(sf::RenderTarget& target) { 
	target.draw(shape);
}

Enemy::Enemy(float posX, float posY) {
	this->shape.setRadius(rand() % 20 + 20);

	// Using static cast to avoid operator overflow
	this->shape.setPointCount(rand() % 15 + static_cast<size_t>(3));
	this->shape.setPosition(posX, posY);

	this->shape.setFillColor(sf::Color(
		rand() % 255 + 25,
		rand() % 255 + 25,
		rand() % 255 + 25,
		255
	));

	this->type    = 0;
	this->hpMax   = 10;
	this->hp      = this->hpMax;
	this->damage  = 1;
	this->points  = 5;
}

Enemy::~Enemy() { }
