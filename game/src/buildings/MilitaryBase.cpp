#include "../../include/buildings/MilitaryBase.hpp"
#include "../../../engine/include/UnitFactory.hpp"
#include <iostream>
#include "../../../engine/include/Utilities.hpp"

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
		PlayerState& playerState)
	{
		if (toUpdate)
		{
			if (playerState.checkBalance(getIronCost(), getCopperCost(), getSiliconCost()))
			{
				playerState.updatePlayerBalances(-getIronCost(), -getCopperCost(), -getSiliconCost());
				auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
				engine::TilePtr location = map->getTile(xy.first, xy.second);
				build(location, objMan);
			}
		}
	}

	void MilitaryBase::build(engine::TilePtr location, std::shared_ptr<engine::ObjectManager> OM)
	{
		auto unit = engine::unitFactory->create(ObjectType::Melee, location, getOwner());
		OM->addUnit(unit);
	}

	std::string MilitaryBase::getName()
	{
		return "Military Base";
	}

	std::string MilitaryBase::getBuildUnitName()
	{
		return "Melee";
	}
}