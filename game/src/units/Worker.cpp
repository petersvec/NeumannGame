#include "../../include/units/Worker.hpp"
#include "../../../engine/include/UnitFactory.hpp"
#include <iostream>

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
			objMan->removeUnit(object);
		}
	}

	void Worker::build(game::PlayerState& playerState, engine::TilePtr location, std::shared_ptr<engine::ObjectManager> OM)
	{

	}

	void Worker::workerBuild(game::PlayerState& playerState, engine::TilePtr location, std::shared_ptr<engine::ObjectManager> OM, game::ObjectType type)
	{
		if (type == ObjectType::AirBase ||
			type == ObjectType::MilitaryBase ||
			type == ObjectType::Tower)
		{
			if (!playerState.checkBalance(500, 500, 500))
			{
				return;
			}

			playerState.updatePlayerBalances(-500, -500, -500);
		}
		else if (type == ObjectType::Mine)
		{
			if (!playerState.checkBalance(200, 200, 200))
			{
				return;
			}
			playerState.updatePlayerBalances(-200, -200, -200);
		}
		else if (type == ObjectType::SpaceStation)
		{
			if (!playerState.checkBalance(2000, 2000, 2000))
			{
				return;
			}
			
			playerState.updatePlayerBalances(-2000, -2000, -2000);
		}
		else
		{
			return;
		}
		auto unit = engine::unitFactory->create(type, location, getOwner());
		OM->addUnit(unit);
	}
  
	std::string Worker::getName()
	{
		return "Worker";
	}
}