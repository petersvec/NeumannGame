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
			 ObjectType type,
			 const sf::Texture& texture,
			 engine::TilePtr location,
			 unsigned short ironCost,
			 unsigned short copperCost,
			 unsigned short siliconCost,
			 Ownership owner);

		virtual void update(std::shared_ptr<engine::Map> map,
							std::shared_ptr<engine::ObjectManager> objMan,
							bool toUpdate,
							PlayerState& playerState,
							ObjectType objType) override;
		void mine(PlayerState&);

		unsigned short getMiningCapacity()
		{
			return m_miningCapacity;
		}

		void setMiningCapacity(unsigned short miningCapacity)
		{
			m_miningCapacity = miningCapacity;
		}
		std::string getName() override;
	};
}