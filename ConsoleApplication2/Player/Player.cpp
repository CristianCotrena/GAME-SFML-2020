#include "Player.h"
#include <iostream> 
#include <SFML/Graphics.hpp>
#include "../Animation/Player/PlayerAnimation.h"

const float NORMAL   = 0;
const float ESQUERDA = 1;
const float DIREITA  = 2;
const float MORTE    = 3;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(true) {
	animation.SetInfo(texture, imageCount, switchTime);
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(50.0f, 50.0f));
	body.setOrigin(sf::Vector2f(50.0f, 50.0f)/2.0f);
	body.setPosition(300.0f, 300.0f);
	body.setTexture(texture);
}

void Player::Reset() {
	row = 0;
	faceRight = true;
	body.setOrigin(sf::Vector2f(50.0f, 50.0f) / 2.0f);
	body.setPosition(300.0f, 300.0f);
}

void Player::Update(float deltaTime) {
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		row = NORMAL;
		movement.y += speed * deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		row = NORMAL;
		movement.y -= speed * deltaTime;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		row = ESQUERDA;
		movement.x -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		row = DIREITA;
		movement.x += speed * deltaTime;
	}

	if (movement.x == 0.0f) 
		row = NORMAL;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) 
		row = MORTE;

	animation.Update(row, deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
	std::cout << "y = " << body.getPosition().y << std::endl;
	
	if (body.getPosition().x < 24)
		body.setPosition(24.0f, body.getPosition().y);
	if (body.getPosition().x > 676)
		body.setPosition(676.0f, body.getPosition().y);

	if (body.getPosition().y < 75) 
		body.setPosition(body.getPosition().x, 75.0f);
	else if (body.getPosition().y > 506)
		body.setPosition(body.getPosition().x, 506.0f);
}

void Player::Draw(sf::RenderWindow& window) {
	window.draw(body);
}
