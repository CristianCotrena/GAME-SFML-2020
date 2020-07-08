#pragma once
#include <SFML/Graphics.hpp>
#include "../Animation/Player/PlayerAnimation.h"

class Fase {
public:
	Fase(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	Fase();
	void Reset();
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
	sf::RectangleShape body;
private:
	sf::Vector2f position;
	PlayerAnimation animation;
	unsigned int row;
};
