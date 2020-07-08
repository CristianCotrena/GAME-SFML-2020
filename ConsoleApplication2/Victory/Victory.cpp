#include "Victory.h"

bool SPACE_UP = true;

Victory::~Victory() {}
Victory::Victory(float width, float height) {
	font.loadFromFile("font.ttf");

	populateIndex(0, ":: VITORIA ::", sf::Vector2f(220, height / (VICTORY_SIZE + 1) * 1));
	populateIndex(1, "PRESS SPACE TO CONTINUE", sf::Vector2f(40, height / (VICTORY_SIZE + 1) * 2));

	list[0].setFillColor(sf::Color::Green);
}

void Victory::populateIndex(int index, sf::String text, sf::Vector2f position) {
	list[index].setFont(font);
	list[index].setFillColor(sf::Color::Yellow);
	list[index].setString(text);
	list[index].setPosition(position);
}

void Victory::draw(sf::RenderWindow &window) {
	for (int i = 0; i < VICTORY_SIZE; i++)
		window.draw(list[i]);
}