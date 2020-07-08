#pragma once
#include "../Collision/Collider.h"
#include "./Platform.h"

#define PLATFORM_SIZE 40

class PlatformArray {
public:
	PlatformArray(sf::Texture* texture);
	void Reset();
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
	bool GetCollider(Collider& other);
	bool GetColliderDeath(Collider& other);
	Platform list[PLATFORM_SIZE];
};

