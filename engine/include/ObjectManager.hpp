#pragma once

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>

#include "IObject.hpp"
#include "../../game/include/Ownership.hpp"

namespace engine
{
	class ObjectManager
	{
	public:
		ObjectManager();
		
		void drawAll(sf::RenderWindow* window);
		void addUnit(IObjectPtr unit);
		IObjectPtr findUnit(int x, int y, game::Ownership player);
		std::vector<IObjectPtr> getPlayerObjects();

	private:
		std::vector<IObjectPtr> playerObjectVector;
	};
}
