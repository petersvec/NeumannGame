#include "../../include/buildings/MilitaryBase.hpp"

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
			makeMelee(unitFactory, location);
		}
	}

	void MilitaryBase::makeMelee(engine::UnitFactoryPtr unitFactory, engine::TilePtr location)
	{
		unitFactory.get()->create(ObjectType::Melee, location, getOwner());
	}
  
	std::string MilitaryBase::getName()
	{
		return "Military Base";
	}
}