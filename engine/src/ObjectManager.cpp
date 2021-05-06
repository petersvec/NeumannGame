#include "../include/ObjectManager.hpp"
#include "../include/IObject.hpp"
#include <iostream>
#include <algorithm>

namespace engine
{
	ObjectManager::ObjectManager() {}

	std::vector<std::shared_ptr<IObject>> ObjectManager::getPlayerObjects()
	{
		return playerObjectVector;
	}

	void ObjectManager::drawAll(sf::RenderTexture* window)
	{
		for (int it = 0; it < playerObjectVector.size(); it++)
		{
			playerObjectVector[it]->draw(window);
		}
	}

	void ObjectManager::addUnit(std::shared_ptr<IObject> unit)
	{
		playerObjectVector.push_back(unit);
	}

	void ObjectManager::removeUnit(std::shared_ptr<IObject> unit)
	{
		playerObjectVector.erase(std::remove(playerObjectVector.begin(), playerObjectVector.end(), unit), playerObjectVector.end());
	}

	void ObjectManager::addLoadedUnit(std::shared_ptr<IObject> unit)
	{
		playersLoadedObjectsVector.push_back(unit);
	}

	void ObjectManager::removeLoadedUnit(std::shared_ptr<IObject> unit)
	{
		playersLoadedObjectsVector.erase(std::remove(playersLoadedObjectsVector.begin(), playersLoadedObjectsVector.end(), unit), playersLoadedObjectsVector.end());
	}

	std::shared_ptr<IObject> ObjectManager::findUnit(int x, int y, game::Ownership player)
	{
		for (int it = 0; it < playerObjectVector.size(); it++)
		{
			if (playerObjectVector[it]->getPosition().x == x && playerObjectVector[it]->getPosition().y == y)
			{
				std::cout << "found ";
				std::cout << (int)playerObjectVector[it]->getOwner();
				std::cout << '\n';
				if (player == playerObjectVector[it]->getOwner())
				{
					std::cout << "Unit selected\n";
					return playerObjectVector[it];
				}
				else
				{
					std::cout << "Other players unit\n";
				}
				return this->playerObjectVector[it];
			}
			
		}
		return nullptr;
	}
}