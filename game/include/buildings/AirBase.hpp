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
			game::ObjectType type,
			const sf::Texture& texture,
			engine::TilePtr location,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost,
			game::Ownership owner);

		virtual void update(std::shared_ptr<engine::Map> map, engine::ObjectManager objMan, bool toUpdate, engine::UnitFactory unitFactory) override;
		void makeRanged(engine::UnitFactory unitFactory);
	};
}