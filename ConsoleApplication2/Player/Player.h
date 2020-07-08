#pragma once
#include <SFML/Graphics.hpp>
#include "../Animation/Player/PlayerAnimation.h"
#include "../Collision/Collider.h"

class Player {
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	void Reset();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }
	sf::RectangleShape body;
private:
	PlayerAnimation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};