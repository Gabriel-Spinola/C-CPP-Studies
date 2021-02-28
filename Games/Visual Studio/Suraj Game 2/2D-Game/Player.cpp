#include "Player.h"

// Private Methods
void Player::Input() {
	this->rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	this->leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

void Player::WindowBoundsCollision(const sf::RenderTarget* target) {
	// ! Tip: When using values that need to be updated every time
	// ! In every change that you make and you also need to be precise with it
	// ! dont store this values in variable. Cause this variable you get the first value
	// ! and use this to all test cases... And that's hurts... A LOT | 30 min to realize that ):

	if(this->shape.getGlobalBounds().left <= 0.f) {
		this->shape.setPosition(0.f, this->shape.getPosition().y);
	}

	if(this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x) {
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getPosition().y);
	}
	
	if(this->shape.getGlobalBounds().top <= 0.f) {
		this->shape.setPosition(this->shape.getPosition().x, 0.f);
	}

	if(this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y) {
		this->shape.setPosition(this->shape.getPosition().x, target->getSize().y - this->shape.getGlobalBounds().height);
	}
}

void Player::Movement(const sf::RenderTarget* target) {
	Input();

	// Move
	if(this->leftKey) {
		shape.move(-this->moveSpeed, 0.f);
	}
	else if(this->rightKey) {
		shape.move(this->moveSpeed, 0.f);
	}
	
	if(this->upKey) {
		shape.move(0.f, -this->moveSpeed);
	}
	else if(this->downKey) {
		shape.move(0.f, this->moveSpeed);
	}

	WindowBoundsCollision(target);
}

void Player::TakeDamage(const int damage) { 
	if(this->hp > 0) {
		this->hp -= damage;
	}
	else {
		this->hp = 0;
	}
}

void Player::Heal(const int health) {
	if(this->hp < this->hpMax) {
		this->hp += health;
	}
	else if(this->hp > this->hpMax) {
		this->hp = this->hpMax;
	}
}

const bool Player::Die() const {
	return this->hp <= 0;
}

// Init, Render and Update
void Player::Init(float x, float y) { 
	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setPosition(x, y);
}

void Player::Render(sf::RenderTarget* target) { 
	target->draw(this->shape);
}

void Player::Update(sf::RenderTarget* target) {
	Movement(target);
}

// Constructor and Destructor
Player::Player(float x, float y) {
	Init(x, y);
}

Player::~Player() { }

// Getters
const sf::RectangleShape& Player::getShape() const { return this->shape; }
const int& Player::getHp() const { return this->hp; }
const int& Player::getHpMax() const { return this->hpMax; }
