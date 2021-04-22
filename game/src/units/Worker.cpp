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
			//build(objType, location);
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

	void Worker::workerBuild(engine::TilePtr location, engine::ObjectManager* OM, int number)
	{
		
		if (number == 1) {
			auto unit = engine::unitFactory->create(ObjectType::SpaceStation, location, getOwner());
			std::cout << "hereee";
			OM->addUnit(unit);
		}
		if (number == 2) {
			auto unit = engine::unitFactory->create(ObjectType::MilitaryBase, location, getOwner());
			OM->addUnit(unit);
		}
		if (number == 3) {
			auto unit = engine::unitFactory->create(ObjectType::AirBase, location, getOwner());
			OM->addUnit(unit);
		}
		
	}
  
	std::string Worker::getName()
	{
		return "Worker";
	}
}