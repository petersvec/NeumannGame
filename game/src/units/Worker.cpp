#include "../../include/units/Worker.hpp"
#include "../../../engine/include/UnitFactory.hpp"
#include "../../../engine/include/JsonParser.hpp"
#include "../../include/units/Probe.hpp"

namespace game
{
	Worker::Worker(unsigned short hp,
				   ObjectType type,
				   const sf::Texture& texture,
				   engine::TilePtr location,
				   unsigned char moveSpeed,
				   unsigned char range,
				   unsigned char attackDamage,
				   unsigned char armour,
				   Ownership owner)
				   :
				   IUnit{ hp, type, texture, location, moveSpeed, range, attackDamage, armour, owner},
				   engine::IObject{ hp, type, texture, location, owner }
	{}

	void Worker::attack(std::shared_ptr<engine::IObject> object, std::shared_ptr<engine::ObjectManager> objMan)
  	{
		if (object == nullptr)
		{
			return;
		}
		
		if (engine::TileDistance(getPosition(), object->getPosition()) > getRange())
		{
			return;
		}

		if (object->getHp() > getAttackDamage())
		{
			object->setHp(object->getHp() - getAttackDamage());
		}
		else
		{
			if (object->getType() == ObjectType::Probe)
			{
				auto probe = dynamic_cast<Probe*>(object.get());

				if (probe->isLoaded())
				{
					objMan->removeLoadedUnit(probe->getTroop());
				}
			}
			objMan->removeUnit(object);
		}
	}

	bool Worker::build(PlayerState& playerState1, PlayerState& playerState2, int* changed, engine::TilePtr location, std::shared_ptr<engine::ObjectManager> OM, ObjectType type)
	{
		if (type == ObjectType::AirBase)
		{
			auto cost = engine::config->GetCost("AirBase");

			if (!playerState1.checkBalance(cost["iron"], cost["copper"], cost["silicon"]))
			{
				return false;
			}

			playerState1.updatePlayerBalances(-cost["iron"], -cost["copper"], -cost["silicon"]);
		}
		else if (type == ObjectType::MilitaryBase)
		{
			auto cost = engine::config->GetCost("MilitaryBase");

			if (!playerState1.checkBalance(cost["iron"], cost["copper"], cost["silicon"]))
			{
				return false;
			}

			playerState1.updatePlayerBalances(-cost["iron"], -cost["copper"], -cost["silicon"]);
		}
		else if (type == ObjectType::Tower)
		{
			auto cost = engine::config->GetCost("Tower");

			if (!playerState1.checkBalance(cost["iron"], cost["copper"], cost["silicon"]))
			{
				return false;
			}

			playerState1.updatePlayerBalances(-cost["iron"], -cost["copper"], -cost["silicon"]);
		}
		else if (type == ObjectType::Mine)
		{
			auto cost = engine::config->GetCost("Mine");

			if (!playerState1.checkBalance(cost["iron"], cost["copper"], cost["silicon"]))
			{
				return false;
			}

			playerState1.updatePlayerBalances(-cost["iron"], -cost["copper"], -cost["silicon"]);
		}
		else if (type == ObjectType::SpaceStation)
		{
			auto cost = engine::config->GetCost("SpaceStation");

			if (!playerState1.checkBalance(cost["iron"], cost["copper"], cost["silicon"]))
			{
				return false;
			}

			playerState1.updatePlayerBalances(-cost["iron"], -cost["copper"], -cost["silicon"]);
		}
		else
		{
			return false;
		}

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

		auto unit = engine::unitFactory->create(type, location, getOwner());
		OM->addUnit(unit);
		return true;
	}
  
	std::string Worker::getName()
	{
		return "Worker";
	}
}