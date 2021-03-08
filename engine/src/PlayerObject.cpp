#include "../include/PlayerObject.hpp"

namespace engine
{
	PlayerObject::PlayerObject()
	{
		this->circle.setFillColor(sf::Color::Green);
		this->circle.setRadius(40);
		this->owner = 1;
		this->value = 1;
		
	}

	void PlayerObject::setPos(int xPos, int yPos, int Utype)
	{
		this->circle.setPosition(xPos * tileSize, yPos * tileSize);
	}

	
	
	void PlayerObject::drawObj(sf::RenderWindow *RWindow)
	{
		RWindow->draw(this->circle);
	}
	void PlayerObject::updateObj()
	{
	}
}