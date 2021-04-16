#include "../include/PlayerObject.hpp"

namespace engine
{
	PlayerObject::PlayerObject()
	{
		circle.setFillColor(sf::Color::Green);
		circle.setRadius(25);
		owner = 1;
		value = 1;
	}

	void PlayerObject::setPos(int xPos, int yPos)
	{
		circle.setPosition(xPos * tileSize, yPos * tileSize);
	}
	
	void PlayerObject::drawObj(sf::RenderWindow *RWindow)
	{
		RWindow->draw(circle);
	}

	void PlayerObject::updateObj()
	{

	}
	
	void PlayerObject::move(int x, int y)
	{
		setPos(x, y);
	}
}