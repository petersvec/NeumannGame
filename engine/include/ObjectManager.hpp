#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

namespace engine
{
	class ObjectManager
	{
	public:
		ObjectManager();
		
		void drawAll(sf::RenderWindow*);
		void addUnit(IObjectPtr);
		IObjectPtr findUnit(int, int, game::Ownership);
		std::vector<IObjectPtr> getPlayerObjects();

	private:
		std::vector<IObjectPtr> playerObjectVector;
	};
}
