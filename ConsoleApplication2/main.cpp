#include <SFML/Graphics.hpp>
#include <iostream>

#include "./Player/Player.h"
#include "./Animation/Player/PlayerAnimation.h"
#include "./Platform/Platform.h"

/*
	PUCRS 2020
	NOMES: 
		CRISTIAN COTRENA
		HUGO NETO
*/

int main() {
	sf::RenderWindow window(
		sf::VideoMode(512, 512), 
		"RIVER RAID :: Cristian Cotrena :: Hugo Neto", 
		sf::Style::Close | sf::Style::Resize
	);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("player.png"); //("./Textures/player/player.png");

	Player player(&playerTexture, sf::Vector2u(5, 4), 0.3f, 100.0f);

	Platform platA(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(150.0f, 100.0f));
	Platform platB(nullptr, sf::Vector2f(100.f, 100.0f), sf::Vector2f(150.0f, 0.0f));
	Platform platC(nullptr, sf::Vector2f(100.f, 100.0f), sf::Vector2f(300.0f, 0.0f));

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {
	
		deltaTime = clock.restart().asSeconds();
		
		sf::Event event;
		while (window.pollEvent(event)) {

			switch (event.type) {
				//QUANDO FECHA A APLICAÇÃO . . .
				case sf::Event::Closed:
					window.close();
					break;

				//QUANDO DIMENCIONA A TELA . . .
				case sf::Event::Resized:
					std::cout 
						<< "New window width : " << event.size.width 
						<< "new window heigth: " << event.size.height << std::endl;
					break;
				//PEGA VALOR DA TECLA DIGITADA . . .
				case sf::Event::TextEntered:
					//std::cout
					//	<< "Unicode tecla : " << event.text.unicode << std::endl;
					//Player::move(event, &player);  //.move(event.text.unicode);
					break;
			}
		}

		player.Update(deltaTime);

		Collider playerCollision = player.GetCollider();

		platA.GetCollider().CheckCollision(playerCollision, 0.0f);
		//platB.GetCollider().CheckCollision(playerCollision, 1.0f);
		//platC.GetCollider().CheckCollision(playerCollision, 1.0f);

		window.clear();
		player.Draw(window);
		platA.Draw(window);
		//platB.Draw(window);
		//platC.Draw(window);
		window.display();
	}

    return 0;
}
