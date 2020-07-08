#include "Options.h"

Options::~Options() {}
Options::Options(float width, float height) {
	font.loadFromFile("font.ttf");

	populateIndex(0, ":: CREATED BY ::", sf::Vector2f(20.0f, 50.0f), 25);
	populateIndex(1, "CRISTIAN COTRENA", sf::Vector2f(100, 100.0f), 12);
	populateIndex(2, "HUGO NETO", sf::Vector2f(100, 150.0f), 12);

	populateIndex(3, ":: COMANDOS ::", sf::Vector2f(20.0f, 200.0f), 25);
	populateIndex(4, "Movevent . W . A . S . D .", sf::Vector2f(100, 250.0f), 12);
	populateIndex(5, "Shoot . P .", sf::Vector2f(100, 300.0f), 12);
	populateIndex(6, "Confirm . Enter .", sf::Vector2f(100, 350.0f), 12);

	populateIndex(7, "PRESS SPACE TO CONTINUE", sf::Vector2f(40, 500.0f), 30);

	options[0].setFillColor(sf::Color::Yellow);
	options[3].setFillColor(sf::Color::Yellow);
	options[7].setFillColor(sf::Color::Yellow);
}

void Options::populateIndex(int index, sf::String text, sf::Vector2f position, int size) {
	options[index].setFont(font);
	options[index].setFillColor(sf::Color::Green);
	options[index].setString(text);
	options[index].setPosition(position);
	options[index].setCharacterSize(size);
}

void Options::draw(sf::RenderWindow &window) {
	for (int i = 0; i < OPTIONS_SIZE; i++) {
		window.draw(options[i]);
	}
}
