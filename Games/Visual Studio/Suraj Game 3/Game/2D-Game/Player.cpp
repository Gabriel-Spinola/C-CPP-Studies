#include "Player.h"

void Player::InitTexture() {
	// Load Texture from image
	if(!this->texture.loadFromFile("Textures/ship.png")) {
		std::cout << "ERROR::PLAYER::INITTEXTURE | Could not load texture file ):" << std::endl;
	}
}

void Player::InitSprite() {
	// Set the texture to the sprite
	this->sprite.setTexture(texture);

	/// Resize the sprite

	// Ther paremeters are factors, not the actual scale number
	// Basically 0.1f = 10%
	this->sprite.scale(0.1f, 0.1f);
}

void Player::Move(const int dirX, const int dirY) {
	sprite.move(moveSpeed * dirX, moveSpeed * dirY);
}

void Player::Movement() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		Move(1, 0);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		Move(-1, 0);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		Move(0, -1);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		Move(0, 1);
}

void Player::Update() {
	Movement();
}

void Player::Render(sf::RenderTarget& target) { 
	target.draw(sprite);
}

Player::Player() {
	this->moveSpeed = 10.f;

	this->InitTexture();
	this->InitSprite();
}

Player::~Player() {

}