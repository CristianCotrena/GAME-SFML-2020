#include "Menu.h"

bool PRESS_UP = true;

Menu::~Menu() {}
Menu::Menu(float width, float height){
	font.loadFromFile("font.ttf");

	populateIndex(0,"INICIAR", sf::Vector2f(width / 2, height / (MENU_SIZE + 1) * 1));
	populateIndex(1,"OPTIONS", sf::Vector2f(width / 2, height / (MENU_SIZE + 1) * 2));
	populateIndex(2,"SAIR"   , sf::Vector2f(width / 2, height / (MENU_SIZE + 1) * 3));

	menu[0].setFillColor(sf::Color::Red);
	selectedItemIndex = 0;
}

void Menu::populateIndex(int index, sf::String text, sf::Vector2f position) {
	menu[index].setFont(font);
	menu[index].setFillColor(sf::Color::White);
	menu[index].setString(text);
	menu[index].setPosition(position);
}

void Menu::Reset() {
	menu[0].setFillColor(sf::Color::Red);
	menu[1].setFillColor(sf::Color::White);
	menu[2].setFillColor(sf::Color::White);
	selectedItemIndex = 0;
}

void Menu::draw(sf::RenderWindow &window){
	for (int i = 0; i < MENU_SIZE; i++){
		window.draw(menu[i]);
	}
}

void Menu::MoveUp(){
	PRESS_UP = !PRESS_UP;
	if (selectedItemIndex - 1 >= 0 && PRESS_UP){
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown(){
	PRESS_UP = !PRESS_UP;
	if (selectedItemIndex + 1 < MENU_SIZE && PRESS_UP){
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
