#include "../../include/units/Worker.hpp"
#include "../../../engine/include/UnitFactory.hpp"

namespace game
{
	Worker::Worker(unsigned short hp,
				   ObjectType type,
				   const sf::Texture& texture,
				   engine::TilePtr location,
				   unsigned char moveSpeed,
				   unsigned char attackDamage,
				   unsigned char armour,
				   Ownership owner)
				   :
				   IUnit{ hp, type, texture, location, moveSpeed, attackDamage, armour, owner},
				   engine::IObject{ hp, type, texture, location, owner }
	{}

	void Worker::update(std::shared_ptr<engine::Map> map,
						std::shared_ptr<engine::ObjectManager> objMan,
						bool toUpdate,
						PlayerState& playerState,
						ObjectType objType)
	{
		Ownership enemy = ((getOwner() == Ownership::Player1) ? Ownership::Player2 : Ownership::Player1);
		attack(objMan->findUnit(getPosition().x, getPosition().y, enemy));

		if (toUpdate)
		{
			auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
			engine::TilePtr location = map->getTile(xy.first, xy.second);
			build(playerState, objType, location);
		}
	}

	void Worker::attack(std::shared_ptr<engine::IObject> object)
	{
		if (object == nullptr)
		{
			return;
		}
		
		if (engine::TileDistance(getPosition(), object->getPosition()) > getMoveSpeed())
		{
			return;
		}

		object->setHp(object->getHp() - getAttackDamage());
	}

	void Worker::build(PlayerState& playerState, ObjectType objType, engine::TilePtr location)
	{
		if (objType == ObjectType::AirBase ||
			objType == ObjectType::MilitaryBase ||
			objType == ObjectType::Tower)
		{
			if (!playerState.checkBalance(500, 500, 500))
			{
				return;
			}
		}
		else if (objType == ObjectType::Mine)
		{
			if (!playerState.checkBalance(200, 200, 200))
			{
				return;
			}
		}
		else if (objType == ObjectType::SpaceStation)
		{
			if (!playerState.checkBalance(2000, 2000, 2000))
			{
				return;
			}
		}
		else
		{
			return;
		}
		engine::unitFactory->create(objType, location, getOwner());
	}
  
	std::string Worker::getName()
	{
		return "Worker";
	}
}