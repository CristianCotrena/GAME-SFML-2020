#include "Death.h"

bool ENTER_UP = true;

Death::~Death() {}
Death::Death(float width, float height) {
	font.loadFromFile("font.ttf"); 

	populateIndex(0,":: GAME OVER ::",sf::Vector2f(175, height / (DEATH_SIZE + 1) * 1));
	populateIndex(1,"PRESS SPACE TO CONTINUE", sf::Vector2f(40, height / (DEATH_SIZE + 1) * 2));

	death[0].setFillColor(sf::Color::Red);
}

void Death::populateIndex(int index, sf::String text, sf::Vector2f position) {
	death[index].setFont(font);
	death[index].setFillColor(sf::Color::Yellow);
	death[index].setString(text);
	death[index].setPosition(position);
}

void Death::draw(sf::RenderWindow &window){
	for (int i = 0; i < DEATH_SIZE; i++){
		window.draw(death[i]);
	}
}
