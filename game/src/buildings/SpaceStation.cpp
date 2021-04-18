#include "../../include/buildings/SpaceStation.hpp"

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
							  engine::ObjectManager objMan,
							  bool toUpdate,
							  engine::UnitFactoryPtr unitFactory,
							  PlayerState& playerState,
							  ObjectType objType)
	{
		if (toUpdate)
		{
			auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
			engine::TilePtr location = map->getTile(xy.first, xy.second);
			makeWorker(unitFactory, location);
		}
	}

	void SpaceStation::makeWorker(engine::UnitFactoryPtr unitFactory, engine::TilePtr location)
	{
		unitFactory.get()->create(ObjectType::Worker, location, getOwner());
	}
  
	std::string SpaceStation::getName()
	{
		return "Space station";
	}
}