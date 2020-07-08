#pragma once
#include "SFML/Graphics.hpp"

#define PLACAR_SIZE 2

class Placar {
public:
	Placar(float width, float height);
	~Placar();
	void Reset();
	void draw(sf::RenderWindow &window);
	void PlacarUp();
	int placar;

private:
	void populateIndex(int index, sf::String text, sf::Vector2f position);
	sf::Font font;
	sf::Text list[PLACAR_SIZE];
	sf::RectangleShape fundo;
};