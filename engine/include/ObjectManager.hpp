#pragma once
#include "PlayerObject.hpp"
#include <vector>

namespace engine
{
	class ObjectManager
	{
		
	public:
		ObjectManager();
		std::vector<PlayerObject> playerObjectVector;
		void drawAll(sf::RenderWindow* window);
		PlayerObject createPO(int x, int y, int type, int value);
		

	};
}
