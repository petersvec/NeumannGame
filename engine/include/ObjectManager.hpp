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
		PlayerObject findUnit(int x, int y);
	private:
		std::vector<PlayerObject> playerObjectVector;
		

	};
}
