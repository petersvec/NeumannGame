#include "../../include/units/Worker.hpp"

namespace game
{
	Worker::Worker(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		engine::TilePtr location,
		unsigned char moveSpeed,
		unsigned char attackDamage,
		unsigned char armour,
		game::Ownership owner)
		:
		IUnit{ hp, type, texture, location, moveSpeed, attackDamage, armour, owner},
		engine::IObject{ hp, type, texture, location, owner }
	{}

	void Worker::update(std::shared_ptr<engine::Map> map,
						engine::ObjectManager objMan,
						bool toUpdate,
						engine::UnitFactoryPtr unitFactory,
						game::PlayerState& playerState,
						game::ObjectType objType)
	{
		Ownership owner = ((getOwner() == Ownership::Player1) ? Ownership::Player2 : Ownership::Player1);
		attack(objMan.findUnit(getPosition().x, getPosition().y, owner));

		if (toUpdate)
		{
			build(unitFactory, objType);
		}
	}

	void Worker::attack(engine::IObjectPtr object)
	{
		if (object == nullptr)
		{
			return;
		}
		object->setHp(object->getHp() - getAttackDamage());
	}

	void Worker::build(engine::UnitFactoryPtr unitFactory, ObjectType objType)
	{
		unitFactory.get()->create(objType, getLocation(), getOwner());
	}
}