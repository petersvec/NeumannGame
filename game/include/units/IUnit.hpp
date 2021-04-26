#pragma once
#include "../../../engine/include/IObject.hpp"
#include "../Tile.hpp"

namespace game
{
	class IUnit;
	using IUnitPtr = std::shared_ptr<IUnit>;

	class IUnit : virtual public engine::IObject
	{
	private:
		unsigned char m_moveSpeed;
		unsigned char m_range;
		unsigned char m_attackDamage;
		unsigned char m_armour;

	protected:
		IUnit(unsigned short hp,
			  ObjectType type,
			  const sf::Texture& texture,
			  engine::TilePtr location,
			  unsigned char moveSpeed,
			  unsigned char range,
		  	  unsigned char attackDamage,
			  unsigned char armour,
			  Ownership owner)
			  :
			  IObject{ hp, type, texture, location, owner },
			  m_moveSpeed{ moveSpeed },
			  m_range{ range },
			  m_attackDamage{ attackDamage },
			  m_armour{ armour }
		{}

	public:
		virtual void attack(std::shared_ptr<engine::IObject>, std::shared_ptr<engine::ObjectManager>) override = 0;

		virtual void move(engine::TilePtr tile, PlayerState& playerState1, PlayerState& playerState2, int* change) override
		{
			if ((engine::TileDistance(getPosition(), tile->getPosition())) <= getMoveSpeed())
			{
				setLocation(tile);

				if (tile->getOccupied() == getOwner())
				{
					return;
				}

				if (tile->getTileType() != TileType::Void)
				{
					if (tile->getOccupied() != Ownership::Unoccupied)
					{
						playerState2.updateLand(-1);
					}

					playerState1.updateLand(1);
					tile->setOccupied(getOwner());
					*change = 1;
				}
			}
		}

		unsigned char getMoveSpeed() override
		{
			return m_moveSpeed;
		}

		unsigned char getRange() override
		{
			return m_range;
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

		void setRange(unsigned char range)
		{
			m_range = range;
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