#pragma once

#include <vector>
#include <memory>

#include "Utilities.hpp"
#include "../../game/include/units/IUnit.hpp"

namespace engine
{
	class ObjectManager
	{
		
	public:
		ObjectManager();
		
		void drawAll(sf::RenderWindow* window);
		void addUnit(game::IUnitPtr unit);
		game::IUnitPtr findUnit(int x, int y, game::Player player);
	private:
		std::vector<game::IUnitPtr > playerObjectVector;
		

	};
}
