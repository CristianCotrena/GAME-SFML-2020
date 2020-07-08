#pragma once
#include "SFML/Graphics.hpp"

#define DEATH_SIZE 2

class Death {
public:
	Death(float width, float height);
	~Death();
	void draw(sf::RenderWindow &window);
private:
	void populateIndex(int index, sf::String text, sf::Vector2f position);
	sf::Font font;
	sf::Text death[DEATH_SIZE];
};
