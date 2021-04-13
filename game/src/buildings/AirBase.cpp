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

	void AirBase::update(std::shared_ptr<engine::Map> map, engine::ObjectManager objMan, bool toUpdate, engine::UnitFactoryPtr unitFactory)
	{
		if (toUpdate)
		{
			makeRanged(unitFactory);
		}
	}

	void AirBase::makeRanged(engine::UnitFactoryPtr unitFactory)
	{
		unitFactory.get()->create(game::ObjectType::Ranged, getLocation(), getOwner());
	}
}