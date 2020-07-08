#pragma once
#include "SFML/Graphics.hpp"

#define OPTIONS_SIZE 8

class Options {
public:
	Options(float width, float height);
	~Options();
	void draw(sf::RenderWindow &window);
private:
	void populateIndex(int index, sf::String text, sf::Vector2f position, int size);
	sf::Font font;
	sf::Text options[OPTIONS_SIZE];
};
