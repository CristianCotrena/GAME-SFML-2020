#include <SFML/Graphics.hpp>
#include "Fase.h"
#include "../Animation/Player/PlayerAnimation.h"

Fase::Fase(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position) :
	animation(true) {
	animation.SetInfo(texture, sf::Vector2u(1, 1), 0.3f);
	this->position = position;
	row = 0;
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}

void Fase::Reset() {
	row = 0;
	body.setPosition(this->position);
}

void Fase::Update(float deltaTime) {
	sf::Vector2f movement(0.0f, 0.0f);
	movement.y += 50.0f * deltaTime;

	if(body.getPosition().y < 2600.0f)
		body.move(movement);

	animation.Update(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void Fase::Draw(sf::RenderWindow & window) {
	window.draw(body);
}
