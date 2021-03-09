#include "../include/ObjectManager.hpp"

namespace engine
{
	ObjectManager::ObjectManager()
	{
		
	}

	PlayerObject ObjectManager::createPO(int x, int y, int type, int value)
	{
		PlayerObject po;
		po.setPos(x, y);
		return po;
	}

	
	
}