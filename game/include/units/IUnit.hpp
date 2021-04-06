#pragma once
#include "../../../engine/include/IObject.hpp"

namespace game
{
	class IUnit;
	using IUnitPtr = std::shared_ptr<IUnit>;

	class IUnit : virtual public engine::IObject
	{
	private:

	protected:
		unsigned char m_moveSpeed;
		unsigned char m_attackDamage;
		unsigned char m_armour;
		
		IUnit(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			engine::TilePtr location,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour,
			Player owner)
			:
			IObject{ hp, type, texture, location, owner },
			m_moveSpeed{ moveSpeed },
			m_attackDamage{ attackDamage },
			m_armour{ armour }
		{}

	public:
		virtual void attack(engine::IObjectPtr object) = 0;
		virtual void move(engine::TilePtr tile, unsigned char tileSize) = 0;

		unsigned char getMoveSpeed()
		{
			return m_moveSpeed;
		}

		void setOwner(Player player)
		{
			m_owner = player;
		}

		Player GetOwner() const
		{
			return m_owner;
		}

		unsigned char getAttackDamage()
		{
			return m_attackDamage;
		}

		unsigned char getArmour()
		{
			return m_armour;
		}

		void setMoveSpeed(unsigned char moveSpeed)
		{
			m_moveSpeed = moveSpeed;
		}

		void setAttackDamage(unsigned char attackDamage)
		{
			m_attackDamage = attackDamage;
		}

		void setArmour(unsigned char armour)
		{
			m_armour = armour;
		}
	};
}