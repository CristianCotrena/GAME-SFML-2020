#pragma once
#include "SFML/Graphics.hpp"

#define MENU_SIZE 3

class Menu {
public:
	Menu(float width, float height);
	~Menu();
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	void Reset();
	int GetPressedItem() { return selectedItemIndex; }
private:
	void populateIndex(int index, sf::String text, sf::Vector2f position);
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MENU_SIZE];
};