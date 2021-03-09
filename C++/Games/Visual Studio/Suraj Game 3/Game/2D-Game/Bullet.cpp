#include "Bullet.h"

void Bullet::Update() { 
	sprite.move(moveSpeed * direction);
}

void Bullet::Render(sf::RenderTarget& target) {
	target.draw(sprite);
}

Bullet::Bullet(sf::Texture* texture, float posX, float posY, int dirX, int dirY, float moveSpeed) {
	this->sprite.setTexture(*texture);

	this->sprite.setPosition(posX, posY);

	this->direction.x = dirX;
	this->direction.y = dirY;

	this->moveSpeed = moveSpeed;
}

Bullet::~Bullet() {
	
}

const sf::FloatRect Bullet::getBounds() const {
	return this->sprite.getGlobalBounds();
}
