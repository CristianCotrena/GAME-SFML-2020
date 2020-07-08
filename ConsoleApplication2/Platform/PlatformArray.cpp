#include "./Platform.h"
#include "./PlatformArray.h"
#include "../Collision/Collider.h"

PlatformArray::PlatformArray(sf::Texture* texture) {
	for (int i = 0; i < PLATFORM_SIZE; i++)
		list[i].SetInfo(texture, sf::Vector2f(50.f, 50.0f));
}

void PlatformArray::Reset() {
	for (int i = 0; i < PLATFORM_SIZE; i++)
		list[i].Reset();
}

void PlatformArray::Update(float deltaTime) {
	for (int i = 0; i < PLATFORM_SIZE; i++)
		list[i].Update(deltaTime);
}

void PlatformArray::Draw(sf::RenderWindow & window) {
	for (int i = 0; i < PLATFORM_SIZE; i++)
		list[i].Draw(window);
}

bool PlatformArray::GetCollider(Collider& other) {
	bool test = false;
	for (int i = 0; i < PLATFORM_SIZE; i++) {
		if (list[i].life) {
			if (list[i].GetCollider().CheckCollision(other, 0.0f)) {
				test = true;
				i = PLATFORM_SIZE;
			}
		}
	}
	return test;
}

bool PlatformArray::GetColliderDeath(Collider& other) {
	bool test = false;
	for (int i = 0; i < PLATFORM_SIZE; i++) {
		if (list[i].life) {
			if (list[i].GetCollider().CheckCollision(other, 0.0f)) {
				list[i].life = false;
				test = true;
				i = PLATFORM_SIZE;
				return true;
			}
		}
	}
	return test;
}
