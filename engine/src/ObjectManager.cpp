#include "../include/ObjectManager.hpp"
#include <iostream>

namespace engine
{
	ObjectManager::ObjectManager()
	{
		
	}

	void ObjectManager::drawAll(sf::RenderWindow* window)
	{
		for (int it = 0; it < this->playerObjectVector.size(); it++)
		{
			this->playerObjectVector[it].drawObj(window);
		}
	}

	void ObjectManager::createPO(int x, int y, int type, int value)
	{
		PlayerObject po;
		po.setPos(x, y);
		this->playerObjectVector.push_back(po);
	}

	PlayerObject ObjectManager::findUnit(int x, int y)
	{
		for (int it = 0; it < this->playerObjectVector.size(); it++)
		{
			if (this->playerObjectVector[it].circle.getPosition().x == x && this->playerObjectVector[it].circle.getPosition().y == y)
			{
				std::cout << "found ";
				std::cout << this->playerObjectVector[it].value;
				std::cout << '\n';
				return this->playerObjectVector[it];
			}
		}	
	}
}