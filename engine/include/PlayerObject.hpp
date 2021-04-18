#pragma once
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
		void setPos(int, int);
		void drawObj(sf::RenderWindow *RWindow);
		void updateObj();
		void move(int, int);

	};
}
