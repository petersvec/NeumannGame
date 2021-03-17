#include "../include/ObjectManager.hpp"

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

	

	
	
}