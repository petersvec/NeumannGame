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
		
		void drawAll(sf::RenderTexture*);
		void addUnit(std::shared_ptr<IObject>);
		void removeUnit(std::shared_ptr<IObject>);
		void addLoadedUnit(std::shared_ptr<IObject>);
		void removeLoadedUnit(std::shared_ptr<IObject>);
		std::shared_ptr<IObject> findUnit(int, int, game::Ownership);
		std::vector<std::shared_ptr<IObject>> getPlayerObjects();

	private:
		std::vector<std::shared_ptr<IObject>> playerObjectVector;
		std::vector<std::shared_ptr<IObject>> playersLoadedObjectsVector;
	};
}
