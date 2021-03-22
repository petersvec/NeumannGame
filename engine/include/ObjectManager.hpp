#pragma once
#include "PlayerObject.hpp"
#include <vector>
#include <memory>

namespace engine
{
	class ObjectManager
	{
		
	public:
		ObjectManager();
		
		void drawAll(sf::RenderWindow* window);
		void createPO(int x, int y, int type, int value);
		std::shared_ptr<PlayerObject> findUnit(int x, int y);
	private:
		std::vector<std::shared_ptr<PlayerObject>> playerObjectVector;
		

	};
}
