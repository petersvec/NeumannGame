#include "../../include/buildings/MilitaryBase.hpp"

namespace game
{
	MilitaryBase::MilitaryBase(unsigned short hp,
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

	void MilitaryBase::update(std::shared_ptr<engine::Map> map,
							  engine::ObjectManager objMan,
							  bool toUpdate,
							  engine::UnitFactoryPtr unitFactory,
							  game::PlayerState playerState1)
	{
		if (toUpdate)
		{
			makeMelee(unitFactory);
		}
	}

	void MilitaryBase::makeMelee(engine::UnitFactoryPtr unitFactory)
	{
		unitFactory.get()->create(game::ObjectType::Melee, getLocation(), getOwner());
	}
}