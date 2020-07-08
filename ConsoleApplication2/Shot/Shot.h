#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/Collider.h"
#include "../Animation/Player/PlayerAnimation.h"

class Shot {
public:
	Shot();
	void Reset();
	void GeneratePosition(float positionX, float positionY);
	void Move(float deltaTime);
	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }
	void Update(float deltaTime);
	void SetInfo(sf::Texture* texture, sf::Vector2f size);
	void Shoot(float positionX, float positionY);
	bool state = false;
private:
	sf::RectangleShape body;
	PlayerAnimation animation;
	sf::Vector2f position;
	unsigned int row;
};
