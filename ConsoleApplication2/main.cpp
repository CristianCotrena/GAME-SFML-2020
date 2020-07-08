#include <SFML/Graphics.hpp>
#include "./Player/Player.h"
#include "./Player/StatusPlayer.h"
#include "./Animation/Player/PlayerAnimation.h"
#include "./Platform/Platform.h"
#include "./Platform/PlatformArray.h"
#include "./Menu/Menu.h"
#include "./Fases/Fase.h"
#include "./Death/Death.h"
#include "./Victory/Victory.h"
#include "./Shot/ShotArray.h"
#include "./Audio/Audio.h"
#include "./Player/Placar.h"
#include "./Options/Options.h"

/*
	PUCRS 2020
	NOMES: 
		CRISTIAN COTRENA
		HUGO NETO
*/

const int MENU	  = 0;
const int PLAY	  = 1;
const int OPTIONS = 2;
const int EXIT	  = 3;
const int DEATH   = 4;
const int VICTORY = 5;

int estado = MENU;
int interval = 0;

int main() {

	sf::RenderWindow window(
		sf::VideoMode(700, 600), 
		"RIVER RAID :: Cristian Cotrena :: Hugo Neto", 
		sf::Style::Close | sf::Style::Resize
	);

	sf::Texture playerTexture, barreiraTexture, faseTexture, shotTexture;
	playerTexture.loadFromFile("player.png");
	barreiraTexture.loadFromFile("barreira.png");
	faseTexture.loadFromFile("mapa.bmp");
	shotTexture.loadFromFile("shot.png");

	Audio audio;
	Menu menu(window.getSize().x, window.getSize().y);
	Death death(window.getSize().x, window.getSize().y);
	Victory victory(window.getSize().x, window.getSize().y);
	Options options(window.getSize().x, window.getSize().y);
	StatusPlayer statusPlayer(window.getSize().x, 200.0f);
	Placar placar(window.getSize().x, window.getSize().y);
	Player player(&playerTexture, sf::Vector2u(5, 4), 0.3f, 100.0f);
	PlatformArray platList(&barreiraTexture);
	ShotArray shotList(&shotTexture);
	Fase fase(&faseTexture, sf::Vector2f(700.0f, 5135.0f), sf::Vector2f(350.0f, -2000.0f));

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		if (interval < 300) {
			interval++;
		}
		sf::Event event;
		while (window.pollEvent(event)) {
			//MENU
			if (estado == MENU) {
				switch (event.key.code) {
				case sf::Keyboard::W:
					audio.playSound('c');
					menu.MoveUp();
					break;
				case sf::Keyboard::S:
					audio.playSound('c');
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					audio.playSound('e');
					switch (menu.GetPressedItem()) {
					case 0:
						estado = PLAY;
						break;
					case 1:
						estado = OPTIONS;
						break;
					case 2:
						estado = EXIT;
						window.close();
						break;
					}
					break;
				}
			}
			//DATH
			if (estado == DEATH) {
				switch (event.key.code) {
				case sf::Keyboard::Space:
					menu.Reset();
					statusPlayer.Reset();
					placar.Reset();
					player.Reset();
					platList.Reset();
					shotList.Reset();
					fase.Reset();
					float deltaTime = 0.0f;
					clock.restart();
					estado = MENU; 
					break;
				}
			}
			//VICTORY
			if (estado == VICTORY) {
				switch (event.key.code) {
				case sf::Keyboard::Space:
					menu.Reset();
					statusPlayer.Reset();
					placar.Reset();
					player.Reset();
					platList.Reset();
					shotList.Reset();
					fase.Reset();
					float deltaTime = 0.0f;
					clock.restart();
					estado = PLAY;
					break;
				}
			}
			//OPTIONS
			if (estado == OPTIONS) {
				switch (event.key.code) {
				case sf::Keyboard::Space:
					estado = MENU;
					break;
				}
			}
			//PLAY
			if (estado == PLAY) {
				switch (event.key.code) {
				case sf::Keyboard::P:
					audio.playSound('h');
					shotList.Shoot(
						player.body.getPosition().x,
						player.body.getPosition().y
					);
				break;
				}
			}
		}
	

		switch (estado) {
			case MENU:
				window.clear();
				menu.draw(window);
				window.display();
				break;
			case DEATH:
				window.clear();
				death.draw(window);
				window.display();
				break;
			case VICTORY:
				window.clear();
				victory.draw(window);
				window.display();
				break;
			case OPTIONS:
				window.clear();
				options.draw(window);
				window.display();
				break;
			case PLAY:
				fase.Update(deltaTime);
				if (fase.body.getPosition().y >= 2600.0f) {
					estado = VICTORY;
				}
				player.Update(deltaTime);
				platList.Update(deltaTime);
				shotList.Update(deltaTime);

				//COLISÃO
				Collider playerCollision = player.GetCollider();
				if (platList.GetCollider(playerCollision)) {
					if (statusPlayer.energy == 0) {
						estado = DEATH;
					}
					statusPlayer.EnergyDown();
				}
				for (int i = 0; i < SHOT_SIZE; i++) {
					Collider collision = shotList.list[i].GetCollider();
					if (shotList.list[i].state) {
						if (platList.GetColliderDeath(collision)) {
							shotList.list[i].state = false;
							placar.PlacarUp();
						}
					}
				}

				window.clear();
				fase.Draw(window);
				player.Draw(window);
				platList.Draw(window);
				shotList.Draw(window);
				statusPlayer.draw(window);
				placar.draw(window);
				window.display();
				break;
		}
	}

    return 0;
}