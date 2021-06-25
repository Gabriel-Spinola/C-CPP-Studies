#include "Enemy.h"

void Enemy::Update() { 
	shape.move(0.f, speed);
}

void Enemy::Render(sf::RenderTarget& target) { 
	target.draw(shape);
}

Enemy::Enemy(float posX, float posY) {
	this->pointCount = rand() % 8 + static_cast<size_t>(3); // min = 3, max = 10
	this->speed = this->pointCount != 3 ? static_cast<float>(this->pointCount / 2) : static_cast<float>(this->pointCount);
	this->type = 0;
	this->hpMax = static_cast<int>(this->pointCount);
	this->hp = this->hpMax;
	this->damage = this->pointCount != 3 ? this->pointCount / 5 : this->pointCount / 2;
	this->points = static_cast<int>(this->pointCount);

	this->shape.setRadius(this->pointCount > 5 ? static_cast<float>(this->pointCount * 3.5) : static_cast<float>(this->pointCount * 5));

	// Using static cast to avoid operator overflow
	this->shape.setPointCount(this->pointCount);
	this->shape.setPosition(posX, posY);

	this->shape.setFillColor(sf::Color(
		rand() % 255 + 25,
		rand() % 255 + 25,
		rand() % 255 + 25,
		255
	));
}

Enemy::~Enemy() { }

const sf::FloatRect Enemy::getBounds() const { return this->shape.getGlobalBounds(); }

const int& Enemy::getPoints() const {
	return this->points;
}

const int& Enemy::getDamage() const {
	return this->damage;
}
