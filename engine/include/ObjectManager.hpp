#pragma once


#include <SFML/Graphics/RenderTexture.hpp>
#include <vector>
#include "../../game/include/Ownership.hpp"
#include <memory>

namespace engine
{
	class IObject;

	class ObjectManager
	{
	public:
		ObjectManager();
		
		void drawAll(sf::RenderTexture* window);
		void addUnit(std::shared_ptr<IObject> unit);
		void removeUnit(std::shared_ptr<IObject>);
		std::shared_ptr<IObject> findUnit(int x, int y, game::Ownership player);
		std::vector<std::shared_ptr<IObject>> getPlayerObjects();

	private:
		std::vector<std::shared_ptr<IObject>> playerObjectVector;
	};
}
