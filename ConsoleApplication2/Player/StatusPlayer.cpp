#include "StatusPlayer.h"
#include <iostream>

int MAX		 = 300;
int INTERVAL = 10;

StatusPlayer::~StatusPlayer() {}
StatusPlayer::StatusPlayer(float width, float height) {
	font.loadFromFile("font.ttf");

	energy = MAX;

	fundo.setSize(sf::Vector2f(700.0f, 300.0f));
	fundo.setPosition(sf::Vector2f(0.0f, 535.0f));
	fundo.setFillColor(sf::Color::Black);

	populateIndex(0, "ENERGY", sf::Vector2f(10.0f, 550.0f));
	populateIndex(1, "::::::::::::::::::::::::::::::", sf::Vector2f(200.0f, 550.0f));

	menu[1].setFillColor(sf::Color::Green);
}

void StatusPlayer::populateIndex(int index, sf::String text, sf::Vector2f position) {
	menu[index].setFont(font);
	menu[index].setFillColor(sf::Color::White);
	menu[index].setString(text);
	menu[index].setPosition(position);
}

void StatusPlayer::Reset() {
	energy = MAX;
	menu[1].setString("::::::::::::::::::::::::::::::");
}

void StatusPlayer::draw(sf::RenderWindow &window){
	window.draw(fundo);
	for (int i = 0; i < MENU_SIZE; i++)
		window.draw(menu[i]);
}

void StatusPlayer::EnergyUp() {
	energy = energy + 50;
	EnergyUpdate();
}

void StatusPlayer::EnergyDown() {
	energy = energy-1;
	std::cout << energy << std::endl;
	EnergyUpdate();
}

void StatusPlayer::EnergyUpdate() {
	menu[1].setString("");
	for (int x = 0; x < MAX; x = (x + INTERVAL))
		if (x <= energy)
			menu[1].setString(menu[1].getString() + ":");
}
