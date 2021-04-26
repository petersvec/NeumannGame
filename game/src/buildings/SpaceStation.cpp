#include "../../include/buildings/SpaceStation.hpp"
#include "../../../engine/include/UnitFactory.hpp"

namespace game
{
	SpaceStation::SpaceStation(unsigned short hp,
							   ObjectType type,
							   const sf::Texture& texture,
							   engine::TilePtr location,
							   unsigned short ironCost,
							   unsigned short copperCost,
							   unsigned short siliconCost,
							   Ownership owner)
							   :
							   IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost, owner },
							   IObject{ hp, type, texture, location, owner }
	{}

	void SpaceStation::update(std::shared_ptr<engine::Map> map,
							  std::shared_ptr<engine::ObjectManager> objMan,
							  bool toUpdate,
							  PlayerState& playerState,
							  ObjectType objType)
	{
		if (toUpdate)
		{
			if (playerState.checkBalance(200, 200, 200))
			{
				playerState.updatePlayerBalances(-50, -50, -50);
				auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
				engine::TilePtr location = map->getTile(xy.first, xy.second);
				makeWorker(location);
			}
		}
	}

	void SpaceStation::build(engine::TilePtr location, std::shared_ptr<engine::ObjectManager> OM)
	{
		auto unit = engine::unitFactory->create(ObjectType::Worker, location, getOwner());
		OM->addUnit(unit);
	}
  
	std::string SpaceStation::getName()
	{
		return "Space station";
	}
}