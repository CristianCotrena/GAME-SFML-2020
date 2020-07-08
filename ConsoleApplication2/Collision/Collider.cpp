#include "Collider.h"
#include <SFML/Graphics.hpp>

Collider::Collider(sf::RectangleShape& body) : body(body) {}

bool Collider::CheckCollision(Collider& other, float push) {
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float distance = sqrt((pow(deltaX, 2) + pow(deltaY, 2)));
	
	if (distance < (thisHalfSize.x + otherHalfSize.x) / 2)
		return true;
	return false;
}

