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

	// Resize the sprite

}

void Player::Update() { 

}

void Player::Render(sf::RenderTarget& target) { 
	target.draw(sprite);
}

Player::Player() {
	InitTexture();
	InitSprite();
}

Player::~Player() {

}