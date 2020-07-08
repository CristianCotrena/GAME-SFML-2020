#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "../Animation/Player/PlayerAnimation.h"

const float LIMITE_Y = 800;
const float LIMITE_X = 550;

Platform::Platform() : animation(true) {
}

void Platform::SetInfo(sf::Texture* texture, sf::Vector2f size) {
	life = true;
	animation.SetInfo(texture, sf::Vector2u(5, 1), 0.3f);
	this->position = position;
	row = 0;
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	GeneratePosition();
}

void Platform::GeneratePosition() {
	life = true;
	const float x = ((rand() % 15)*50.0f);
	const float y = -100 - (rand() % 11)*50.0f;
	body.setPosition(sf::Vector2f(x, y));
}

void Platform::Move(float deltaTime) {
	if (body.getPosition().y >= 700) {
		GeneratePosition();
	} else {
		sf::Vector2f movement(0.0f, 0.0f);
		movement.y += 200.0f * deltaTime;
		body.move(movement);
	}
}

void Platform::Reset() {
	row = 0;
	body.setPosition(this->position);
}

void Platform::Update(float deltaTime) {
	animation.Update(row, deltaTime);
	body.setTextureRect(animation.uvRect);
	Move(deltaTime);
}

void Platform::Draw(sf::RenderWindow & window) {
	if (life)
		window.draw(body);
}