#pragma once
#include "../../../engine/include/IObject.hpp"
#include "../player/PlayerState.hpp"

namespace game
{
	class IBuilding : virtual public engine::IObject
	{
	private:

	protected:
		unsigned short m_ironCost;
		unsigned short m_copperCost;
		unsigned short m_siliconCost;

		IBuilding(game::ObjectType type,
			const sf::Texture& texture,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost)
			:
			IObject{ type, texture },
			m_ironCost{ ironCost },
			m_copperCost{ copperCost },
			m_siliconCost{ siliconCost }
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