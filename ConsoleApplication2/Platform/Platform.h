#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/Collider.h"
#include "../Animation/Player/PlayerAnimation.h"

class Platform {
	public:
		Platform();
		void Reset();
		void GeneratePosition();
		void Move(float deltaTime);
		void Draw(sf::RenderWindow& window);
		Collider GetCollider() { return Collider(body); }
		void Update(float deltaTime);
		void SetInfo(sf::Texture* texture, sf::Vector2f size);
		bool life;
	private:
		sf::RectangleShape body;
		PlayerAnimation animation;
		sf::Vector2f position;
		unsigned int row;
};
