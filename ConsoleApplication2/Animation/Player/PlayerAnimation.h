#pragma once
#include <SFML/Graphics.hpp>

class PlayerAnimation {
	public:
		PlayerAnimation(bool test);
		~PlayerAnimation();
		void Update(int row, float deltaTime);
		void SetInfo(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
		sf::IntRect uvRect;
	private:
		sf::Vector2u imageCount;
		sf::Vector2u currentImage;
		float totalTime;
		float switchTime;
};