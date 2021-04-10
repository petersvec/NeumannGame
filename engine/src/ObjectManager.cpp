#include "../include/ObjectManager.hpp"
#include <iostream>
#include "../include/Game.hpp"
#include "../include/Gui.hpp"

namespace engine
{
	ObjectManager::ObjectManager()
	{
		
	}

	void ObjectManager::drawAll(sf::RenderWindow* window)
	{
		for (int it = 0; it < this->playerObjectVector.size(); it++)
		{
			this->playerObjectVector[it]->draw(window);
		}
	}

	void ObjectManager::addUnit(engine::IObjectPtr unit)
	{
		playerObjectVector.push_back(unit);
	}

	engine::IObjectPtr ObjectManager::findUnit(int x, int y, game::Player player)
	{
		for (int it = 0; it < this->playerObjectVector.size(); it++)
		{
			if (this->playerObjectVector[it]->getPosition().x == x && this->playerObjectVector[it]->getPosition().y == y)
			{
				std::cout << "found ";
				std::cout << (int)this->playerObjectVector[it]->GetOwner();
				std::cout << '\n';
				if (player == this->playerObjectVector[it]->GetOwner())
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