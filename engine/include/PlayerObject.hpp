#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
namespace engine
{
	class PlayerObject
	{
	public:
		int value, owner;
		int tileSize = 50;
		sf::CircleShape circle;

		PlayerObject();
		void setPos(int xPos, int yPos, int UType);
		void drawObj(sf::RenderWindow *RWindow);
		void updateObj();

	};
}
