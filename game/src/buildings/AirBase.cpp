#include "../../include/buildings/AirBase.hpp"
#include "../../../engine/include/UnitFactory.hpp"

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
						 std::shared_ptr<engine::ObjectManager> objMan,
						 bool toUpdate,
						 PlayerState& playerState,
				    	 ObjectType objType)
	{
		if (toUpdate)
		{
			auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
			engine::TilePtr location = map->getTile(xy.first, xy.second);
			makeRanged(location);
		}
	}

	void AirBase::makeRanged(engine::TilePtr location)
	{
		engine::unitFactory->create(ObjectType::Ranged, location, getOwner());
	}
  
	std::string AirBase::getName()
	{
		return "Air base";
	}
}