#include "../../include/buildings/SpaceStation.hpp"

namespace game
{
	SpaceStation::SpaceStation(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		engine::TilePtr location,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost,
		game::Ownership owner)
		:
		IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost, owner },
		IObject{ hp, type, texture, location, owner }
	{}

	void SpaceStation::update(std::shared_ptr<engine::Map> map,
							  engine::ObjectManager objMan,
							  bool toUpdate,
							  engine::UnitFactoryPtr unitFactory,
							  game::PlayerState playerState1)
	{
		if (toUpdate)
		{
			makeWorker(unitFactory);
		}
	}

	void SpaceStation::makeWorker(engine::UnitFactoryPtr unitFactory)
	{
		unitFactory.get()->create(game::ObjectType::Worker, getLocation(), getOwner());
	}
}