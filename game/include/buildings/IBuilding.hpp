#pragma once
#include "../../../engine/include/IObject.hpp"

namespace game
{
	class IBuilding : public engine::IObject
	{
	private:

	protected:
		unsigned short m_ironCost;
		unsigned short m_copperCost;
		unsigned short m_siliconCost;

	public:
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