#pragma once

#include <vector>
#include <memory>

#include "Utilities.hpp"
#include "IObject.hpp"

namespace engine
{
	class ObjectManager
	{
	public:
		ObjectManager();
		
		void drawAll(sf::RenderWindow* window);
		void addUnit(engine::IObjectPtr unit);
		engine::IObjectPtr findUnit(int x, int y, game::Ownership player);
		std::vector<engine::IObjectPtr> getPlayerObjects();

	private:
		std::vector<engine::IObjectPtr> playerObjectVector;
	};
}
