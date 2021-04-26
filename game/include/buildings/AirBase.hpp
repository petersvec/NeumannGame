#pragma once
#include "IBuilding.hpp"

namespace game
{
	class AirBase : public IBuilding
	{
	private:

	protected:

	public:
		AirBase(unsigned short hp,
			ObjectType type,
			const sf::Texture& texture,
			engine::TilePtr location,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost,
			Ownership owner);

		virtual void attack(std::shared_ptr<IObject>, std::shared_ptr<engine::ObjectManager>) override {};
		virtual void move(engine::TilePtr, PlayerState&, PlayerState&, int*) override {};
		virtual unsigned char getMoveSpeed() override { return 0; };
		virtual unsigned char getRange() override { return 0; };
		virtual void update(std::shared_ptr<engine::Map> map,
			std::shared_ptr<engine::ObjectManager> objMan,
			bool toUpdate,
			PlayerState& playerState) override;
		void build(engine::TilePtr, std::shared_ptr<engine::ObjectManager> OM);
		virtual std::string getBuildUnitName() override;
		std::string getName() override;
	};
}