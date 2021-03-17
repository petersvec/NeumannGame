#pragma once
#include "PlayerObject.hpp"
#include <vector>

namespace engine
{
	class ObjectManager
	{
		
	public:
		ObjectManager();
		
		void drawAll(sf::RenderWindow* window);
		void createPO(int x, int y, int type, int value);
	private:
		std::vector<PlayerObject> playerObjectVector;
		

	};
}
