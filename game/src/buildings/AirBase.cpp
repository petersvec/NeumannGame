#include "../../include/buildings/AirBase.hpp"

namespace game
{
	AirBase::AirBase(unsigned short hp,
					 ObjectType type,
					 const sf::Texture& texture,
					 engine::TilePtr location,
					 unsigned short ironCost,
					 unsigned short copperCost,
			 		 unsigned short siliconCost,
					 Ownership owner)
					 :
					 IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost, owner},
					 IObject{ hp, type, texture, location, owner }
	{}

	void AirBase::update(std::shared_ptr<engine::Map> map,
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
			makeRanged(unitFactory, location);
		}
	}

	void AirBase::makeRanged(engine::UnitFactoryPtr unitFactory, engine::TilePtr location)
	{
		unitFactory->create(ObjectType::Ranged, location, getOwner());
	}
}