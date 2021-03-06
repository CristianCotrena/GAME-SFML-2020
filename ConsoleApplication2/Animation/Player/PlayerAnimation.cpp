#include "PlayerAnimation.h"

PlayerAnimation::PlayerAnimation(bool test) {}

void PlayerAnimation::SetInfo(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}


void PlayerAnimation::Update(int row, float deltaTime) {
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;
	}

	if (currentImage.x >= imageCount.x)
		currentImage.x = 0;

	uvRect.top  = currentImage.y * uvRect.height;
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.width = abs(uvRect.width);
}

PlayerAnimation::~PlayerAnimation() {}
