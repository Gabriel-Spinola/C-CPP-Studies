#include "Player.h"

void Player::InitTexture() {

}

void Player::InitSprite() {
	this->sprite.setTexture(texture);
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