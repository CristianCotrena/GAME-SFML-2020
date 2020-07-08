#pragma once
#include "SFML/Graphics.hpp"

#define VICTORY_SIZE 2

class Victory {
public:
	Victory(float width, float height);
	~Victory();
	void draw(sf::RenderWindow &window);
private:
	void populateIndex(int index, sf::String text, sf::Vector2f position);
	sf::Font font;
	sf::Text list[VICTORY_SIZE];
};
