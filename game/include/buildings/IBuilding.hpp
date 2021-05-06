#pragma once
#include "../../../engine/include/IObject.hpp"

namespace game
{
	class IBuilding : virtual public engine::IObject
	{
	private:

	protected:
		unsigned short m_ironCost;
		unsigned short m_copperCost;
		unsigned short m_siliconCost;
		

		IBuilding(unsigned short hp,
				  ObjectType type,
				  const sf::Texture& texture,
				  engine::TilePtr location,
				  unsigned short ironCost,
				  unsigned short copperCost,
				  unsigned short siliconCost,
				  Ownership owner)
				  :
				  IObject{ hp, type, texture, location, owner },
				  m_ironCost{ ironCost },
				  m_copperCost{ copperCost },
				  m_siliconCost{ siliconCost }

		{
          m_isBuilding = true;
    }

	public:
		virtual bool update(PlayerState&, PlayerState&, int*, std::shared_ptr<engine::Map>, std::shared_ptr<engine::ObjectManager>)
		{
			return false;
		}

		void update(PlayerState& playerState, int iron, int copper, int silicon)
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