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

	protected:
		unsigned char m_moveSpeed;
		unsigned char m_attackDamage;
		unsigned char m_armour;
		
		
		IUnit(unsigned short hp,
			  ObjectType type,
			  const sf::Texture& texture,
			  engine::TilePtr location,
			  unsigned char moveSpeed,
		  	  unsigned char attackDamage,
			  unsigned char armour,
			  Ownership owner)
			  :
			  IObject{ hp, type, texture, location, owner },
			  m_moveSpeed{ moveSpeed },
			  m_attackDamage{ attackDamage },
			  m_armour{ armour }
		{}

	public:
		virtual void attack(std::shared_ptr<engine::IObject> object) = 0;

		virtual void move(engine::TilePtr tile, unsigned char tileSize, PlayerState& playerState)
		{
			if (engine::TileDistance(getPosition(), tile->getPosition()))
			{
				//move
				setPosition(engine::ScreenToTile(tile->getPosition()));

				//occupy new tile
				playerState.updatePlayerLandConquered();
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