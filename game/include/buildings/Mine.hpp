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

		virtual bool update(PlayerState&, PlayerState&, int*, std::shared_ptr<engine::Map>, std::shared_ptr<engine::ObjectManager>) override;
		virtual void attack(std::shared_ptr<IObject>, std::shared_ptr<engine::ObjectManager>) override {};
		virtual void move(engine::TilePtr, PlayerState&, PlayerState&, int*) override {};
		virtual unsigned char getMoveSpeed() override { return 0; };
		virtual unsigned char getRange() override { return 0; };
		std::string getName() override;
		void mine(PlayerState&);

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