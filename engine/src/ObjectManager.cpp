#include "../include/ObjectManager.hpp"
#include <iostream>
#include "../include/Game.hpp"

namespace engine
{
	ObjectManager::ObjectManager()
	{
		
	}

	void ObjectManager::drawAll(sf::RenderWindow* window)
	{
		for (int it = 0; it < this->playerObjectVector.size(); it++)
		{
			this->playerObjectVector[it]->drawObj(window);
		}
	}

	void ObjectManager::createPO(int x, int y, int type, int value)
	{
		std::shared_ptr<PlayerObject> po = std::make_shared<PlayerObject>();
		po->setPos(x, y);
		this->playerObjectVector.push_back(po);
	}

	std::shared_ptr<PlayerObject> ObjectManager::findUnit(int x, int y,  int player)
	{
		for (int it = 0; it < this->playerObjectVector.size(); it++)
		{
			if (this->playerObjectVector[it]->circle.getPosition().x == x && this->playerObjectVector[it]->circle.getPosition().y == y)
			{
				std::cout << "found ";
				std::cout << this->playerObjectVector[it]->owner;
				std::cout << '\n';
				if (player == this->playerObjectVector[it]->owner)
				{
					std::cout << "Unit selected\n";
					return this->playerObjectVector[it];
				}
				else
				{
					std::cout << "Other players unit\n";
				}
			}
			
		}
		return nullptr;
	}
}