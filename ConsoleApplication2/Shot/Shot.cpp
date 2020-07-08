#include <SFML/Graphics.hpp>
#include "Shot.h"
#include "../Animation/Player/PlayerAnimation.h"

int STATE = false;

Shot::Shot() : animation(true) {}

void Shot::SetInfo(sf::Texture* texture, sf::Vector2f size) {
	animation.SetInfo(texture, sf::Vector2u(1, 1), 0.3f);
	this->position = position;
	row = 0;
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
}

void Shot::Shoot(float positionX, float positionY) {
	GeneratePosition(positionX, positionY);
}

void Shot::GeneratePosition(float positionX, float positionY) {
	body.setPosition(sf::Vector2f(positionX, positionY-50.0f));
	state = true;
}

void Shot::Move(float deltaTime) {
	if (body.getPosition().y <= 0.0f)
		state = false;
	else {
		sf::Vector2f movement(0.0f, 0.0f);
		movement.y -= 300.0f * deltaTime;
		body.move(movement);
	}
}

void Shot::Reset() {
	row = 0;
	state = false;
	body.setPosition(this->position);
}

void Shot::Update(float deltaTime) {
	if (state) {
		animation.Update(row, deltaTime);
		body.setTextureRect(animation.uvRect);
		Move(deltaTime);
	}
}

void Shot::Draw(sf::RenderWindow & window) {
	if (state)
		window.draw(body);
}
