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
			engine::TilePtr location,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost,
			game::Ownership owner);

		virtual void update(std::shared_ptr<engine::Map> map,
							engine::ObjectManager objMan,
							bool toUpdate,
							engine::UnitFactoryPtr unitFactory,
							game::PlayerState& playerState,
							game::ObjectType objType) override;
		void mine(PlayerState& playerState);

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