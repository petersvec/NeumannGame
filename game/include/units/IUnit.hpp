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
			game::Ownership owner)
			:
			IObject{ hp, type, texture, location, owner },
			m_moveSpeed{ moveSpeed },
			m_attackDamage{ attackDamage },
			m_armour{ armour }
		{}

		bool canMove(engine::TilePtr tile, unsigned char tileSize)
		{
			unsigned short x1 = tile->getPosition().x;
			unsigned short y1 = tile->getPosition().y;
			unsigned short x2 = getLocation()->getPosition().x;
			unsigned short y2 = getLocation()->getPosition().y;

			if (getMoveSpeed() > (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) / tileSize))
			{
				return false;
			}
			return true;
		}

	public:
		virtual void attack(engine::IObjectPtr object) = 0;

		void move(engine::TilePtr tile, unsigned char tileSize)
		{
			if (canMove(tile, tileSize))
			{
				//move
				setPosition(engine::ScreenToTile(tile->getPosition()));

				//occupy new tile
				tile->setOccupied(getOwner());
			}
		}

		unsigned char getMoveSpeed()
		{
			return m_moveSpeed;
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