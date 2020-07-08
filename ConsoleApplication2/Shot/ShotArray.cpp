#include "./Shot.h"
#include "./ShotArray.h"
#include "../Collision/Collider.h"

bool press = false;
ShotArray::ShotArray(sf::Texture* texture) {
	for (int i = 0; i < SHOT_SIZE; i++)
		list[i].SetInfo(texture, sf::Vector2f(50.f, 50.0f));
}

void ShotArray::Reset() {
	for (int i = 0; i < SHOT_SIZE; i++)
		list[i].Reset();
}

void ShotArray::Update(float deltaTime) {
	for (int i = 0; i < SHOT_SIZE; i++)
		list[i].Update(deltaTime);
}

void ShotArray::Shoot(float positionX, float positionY) {
	press = !press;
	if (press)
		for (int i = 0; i < SHOT_SIZE; i++)
			if (list[i].state == false) {
				list[i].Shoot(positionX, positionY);
				return;
			}
}

void ShotArray::Draw(sf::RenderWindow & window) {
	for (int i = 0; i < SHOT_SIZE; i++)
		list[i].Draw(window);
}

bool ShotArray::GetCollider(Collider& other) {
	bool test = false;
	for (int i = 0; i < SHOT_SIZE; i++)
		if (list[i].GetCollider().CheckCollision(other, 0.0f)) {
			test = true;
			i = SHOT_SIZE;
		}
	return test;
}
