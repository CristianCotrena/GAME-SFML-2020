#include "Placar.h"
#include <iostream>
#include<string>

Placar::~Placar() {}
Placar::Placar(float width, float height) {
	font.loadFromFile("font.ttf");

	fundo.setSize(sf::Vector2f(700.0f, 50.0f));
	fundo.setPosition(sf::Vector2f(0.0f, 0.0f));
	fundo.setFillColor(sf::Color::Black);

	populateIndex(0, "SCORE ", sf::Vector2f(10.0f, 5.0f));
	populateIndex(1, "0", sf::Vector2f(200.0f, 5.0f));
	
	list[1].setFillColor(sf::Color::Green);
	placar = 0;
}

void Placar::populateIndex(int index, sf::String text, sf::Vector2f position) {
	list[index].setFont(font);
	list[index].setFillColor(sf::Color::White);
	list[index].setString(text);
	list[index].setPosition(position);
}

void Placar::Reset() {
	placar = 0;
	sf::String result = std::to_string(placar);
	list[1].setString(result);
}

void Placar::draw(sf::RenderWindow &window) {
	window.draw(fundo);
	for (int i = 0; i < PLACAR_SIZE; i++)
		window.draw(list[i]);
}

void Placar::PlacarUp() {
	placar = placar + 100;
	sf::String result = std::to_string(placar);
	list[1].setString(result);
}
