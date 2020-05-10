#include "Player.h"
#include <SFML/Graphics.hpp>
#include "../Animation/Player/PlayerAnimation.h"

const float NORMAL   = 0;
const float ESQUERDA = 1;
const float DIREITA  = 2;
const float MORTE    = 3;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime) 
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(50.0f, 50.0f));
	body.setOrigin(sf::Vector2f(50.0f, 50.0f)/2.0f);
	body.setPosition(300.0f, 300.0f);
	body.setTexture(texture);
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

	if (movement.x == 0.0f) row = NORMAL;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
		row = MORTE;
	}

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window) {
	window.draw(body);
}
