#pragma once

#include "../../../engine/include/IObject.hpp"
#include "../player/PlayerState.hpp"
#include "../../../engine/include/Utilities.hpp"

namespace game
{
	class IBuilding : virtual public engine::IObject
	{
	private:

	protected:
		unsigned short m_ironCost;
		unsigned short m_copperCost;
		unsigned short m_siliconCost;
		Player m_owner;

		IBuilding(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			TilePtr location,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost,
			Player owner)
			:
			IObject{ hp, type, texture, location },
			m_ironCost{ ironCost },
			m_copperCost{ copperCost },
			m_siliconCost{ siliconCost },
			m_owner{owner}
		{}

	public:

		void update(PlayerState playerState, int iron, int copper, int silicon)
		{
			playerState.updatePlayerBalances(iron, copper, silicon);
		}

		unsigned short getIronCost()
		{
			return m_ironCost;
		}

		void setIronCost(unsigned short ironCost)
		{
			m_ironCost = ironCost;
		}

		unsigned short getCopperCost()
		{
			return m_copperCost;
		}

		void setCopperCost(unsigned short copperCost)
		{
			m_copperCost = copperCost;
		}

		unsigned short getSiliconCost()
		{
			return m_siliconCost;
		}

		void setSiliconCost(unsigned short siliconCost)
		{
			m_siliconCost = siliconCost;
		}
	};
}