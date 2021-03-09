#pragma once
#include "IObject.hpp"

namespace game
{
	class IUnit : public IObject
	{
	private:

	protected:
		unsigned char m_moveSpeed;
		unsigned char m_attackDamage;
		unsigned char m_armour;

	public:
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

		virtual void attack() = 0;
		virtual void move(unsigned short, unsigned short) = 0;
	};
}