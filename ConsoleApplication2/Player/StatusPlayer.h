#pragma once
#include "SFML/Graphics.hpp"

#define MENU_SIZE 2

class StatusPlayer {
public:
	StatusPlayer(float width, float height);
	~StatusPlayer();
	void Reset();
	void draw(sf::RenderWindow &window);
	void EnergyUp();
	void EnergyDown();
	void EnergyUpdate();
	int energy;
private:
	void populateIndex(int index, sf::String text, sf::Vector2f position);
	sf::Font font;
	sf::Text menu[MENU_SIZE];
	sf::RectangleShape fundo;
};