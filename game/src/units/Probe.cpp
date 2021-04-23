#include "../../include/units/Probe.hpp"
#include "../../../engine/include/UnitFactory.hpp"

namespace game
{
	Probe::Probe(unsigned short hp,
				 ObjectType type,
				 const sf::Texture& texture,
				 engine::TilePtr location,
				 unsigned char moveSpeed,
				 unsigned char attackDamage,
				 unsigned char armour,
				 Ownership owner)
				 :
				 IUnit{ hp, type, texture, location, moveSpeed, attackDamage, armour, owner },
				 IObject{ hp, type, texture, location, owner }
	{}

	unsigned char Probe::getDuplicateTime()
	{
		return m_duplicateTime;
	}

	void Probe::setDuplicateTime(unsigned char duplicateTime)
	{
		m_duplicateTime = duplicateTime;
	}

	bool Probe::isLoaded()
	{
		return m_isLoaded;
	}

	void Probe::setLoading(bool loading)
	{
		m_isLoaded = loading;
	}

	bool Probe::isDuplicating()
	{
		return m_isDuplicating;
	}

	void Probe::setDuplicating(bool duplicating)
	{
		m_isDuplicating = duplicating;
	}

	std::shared_ptr<engine::IObject> Probe::getTroop()
	{
		return m_troop;
	}

	void Probe::setTroop(std::shared_ptr<engine::IObject> troop)
	{
		m_troop = troop;
	}

	void Probe::duplicate(std::shared_ptr<engine::ObjectManager> objMan, std::shared_ptr<engine::Map> map)
	{
		if (getDuplicateTime() == 0)
		{
			auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
			engine::TilePtr location = map->getTile(xy.first, xy.second);
			engine::unitFactory->create(ObjectType::Probe, location, getOwner());
			setDuplicateTime(5);
			setDuplicating(false);
		}
		else
		{
			setDuplicateTime(getDuplicateTime() - 1);
		}
	}

	void Probe::load(std::shared_ptr<IObject> troop)
	{
		if (isLoaded())
		{
			return;
		}

		m_troop = troop;
		setLoading(true);
	}

	void Probe::deploy(std::shared_ptr<engine::ObjectManager> objMan, std::shared_ptr<engine::Map> map)
	{
		if (!isLoaded())
		{
			return;
		}

		auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
		engine::TilePtr location = map->getTile(xy.first, xy.second);

		m_troop->setLocation(location);
		setTroop(nullptr);
		setLoading(false);
	}

	void Probe::attack(std::shared_ptr<engine::IObject> object, std::shared_ptr<engine::ObjectManager> objMan)
	{
		if (object->getHp() > getAttackDamage())
		{
			object->setHp(object->getHp() - getAttackDamage());
		}
		else
		{
			objMan->removeUnit(object);
		}
	}

	std::string Probe::getName()
	{
		return "Probe";
	}
}