#include "../../include/buildings/MilitaryBase.hpp"
#include "../../../engine/include/UnitFactory.hpp"

namespace game
{
	MilitaryBase::MilitaryBase(unsigned short hp,
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

	void MilitaryBase::update(std::shared_ptr<engine::Map> map,
							  std::shared_ptr<engine::ObjectManager> objMan,
							  bool toUpdate,
							  PlayerState& playerState,
							  ObjectType objType)
	{
		if (toUpdate)
		{
			auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
			engine::TilePtr location = map->getTile(xy.first, xy.second);
			makeMelee(location);
		}
	}

	void MilitaryBase::makeMelee(engine::TilePtr location)
	{
		engine::unitFactory->create(ObjectType::Melee, location, getOwner());
	}
  
	std::string MilitaryBase::getName()
	{
		return "Military Base";
	}
}