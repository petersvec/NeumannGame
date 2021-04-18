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

	void Probe::update(std::shared_ptr<engine::Map> map,
					   std::shared_ptr<engine::ObjectManager> objMan,
					   bool toUpdate,
					   PlayerState& playerState,
					   ObjectType objType)
	{
		if (m_loaded)
		{
			deploy();
		}

		duplicate(objMan, map);
	}

	void Probe::duplicate(std::shared_ptr<engine::ObjectManager> objMan, std::shared_ptr<engine::Map> map)
	{
		if (m_duplicateTime == 0)
		{
			auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
			engine::TilePtr location = map->getTile(xy.first, xy.second);
			engine::unitFactory->create(ObjectType::Ranged, location, getOwner());
			m_duplicateTime = 5;
		}
		else
		{
			m_duplicateTime -= 1;
		}
	}

	void Probe::load(engine::IObjectPtr troop)
	{
		m_troop = troop;
		m_loaded = true;
	}

	void Probe::deploy()
	{
		m_troop->setLocation(getLocation());
		m_troop = nullptr;
		m_loaded = false;
	}

	void Probe::attack(engine::IObjectPtr object)
	{
		object->setHp(object->getHp() - getAttackDamage());
	}
	std::string Probe::getName()
	{
		return "Probe";
	}
	
}