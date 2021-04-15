#include "../../include/buildings/AirBase.hpp"

namespace game
{
	AirBase::AirBase(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		engine::TilePtr location,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost,
		game::Ownership owner)
		:
		IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost, owner},
		IObject{ hp, type, texture, location, owner }
	{}

	void AirBase::update(std::shared_ptr<engine::Map> map,
						 engine::ObjectManager objMan,
						 bool toUpdate,
						 engine::UnitFactoryPtr unitFactory,
						 game::PlayerState& playerState,
				    	 game::ObjectType objType)
	{
		if (toUpdate)
		{
			auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
			engine::TilePtr loc = map->getTile(xy.first, xy.second);
			makeRanged(unitFactory, loc);
		}
	}

	void AirBase::makeRanged(engine::UnitFactoryPtr unitFactory, engine::TilePtr location)
	{
		unitFactory->create(game::ObjectType::Ranged, location, getOwner());
	}
}