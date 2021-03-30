#pragma once
#include "IBuilding.hpp"

namespace game
{
	class Mine : public IBuilding
	{
	private:
		unsigned short m_miningCapacity = 500;

	protected:

	public:
		Mine(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			TilePtr location,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost,
			Player owner);

		unsigned short getMiningCapacity()
		{
			return m_miningCapacity;
		}

		void setMiningCapacity(unsigned short miningCapacity)
		{
			m_miningCapacity = miningCapacity;
		}
	};
}