#pragma once
#include "../Collision/Collider.h"
#include "./Shot.h"

#define SHOT_SIZE 20

class ShotArray {
public:
	ShotArray(sf::Texture* texture);
	void Reset();
	void Shoot(float positionX, float positionY);
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
	bool GetCollider(Collider& other);
	Shot list[SHOT_SIZE];
};

