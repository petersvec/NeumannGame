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
		IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost, owner },
		IObject{ hp, type, texture, location, owner }
	{}

	bool AirBase::update(PlayerState& playerState1, PlayerState& playerState2, int* changed,
						 std::shared_ptr<engine::Map> map,
						 std::shared_ptr<engine::ObjectManager> objMan)
	{
		if (playerState1.checkBalance(getIronCost(), getCopperCost(), getSiliconCost()))
		{
			playerState1.updatePlayerBalances(-getIronCost(), -getCopperCost(), -getSiliconCost());
			auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
			engine::TilePtr location = map->getTile(xy.first, xy.second);

			if (location->getTileType() != TileType::Void)
			{
				if (location->getOccupied() == getOwner()) {}
				else if (location->getOccupied() == Ownership::Unoccupied)
				{
					playerState1.updateLand(1);
					location->setOccupied(getOwner());
					*changed = 1;
				}
				else
				{
					playerState1.updateLand(1);
					playerState2.updateLand(-1);
					location->setOccupied(getOwner());
					*changed = 1;
				}
			}

			build(location, objMan);
			return true;
		}
		return false;
	}

	void AirBase::build(engine::TilePtr location, std::shared_ptr<engine::ObjectManager> OM)
	{
		auto unit = engine::unitFactory->create(ObjectType::Ranged, location, getOwner());
		OM->addUnit(unit);
	}

	std::string AirBase::getName()
	{
		return "Air base";
	}

	std::string AirBase::getBuildUnitName()
	{
		return "Ranged";
	}
}