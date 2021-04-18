#pragma once
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "IObject.hpp"
#include "../include/Gui.hpp"

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
