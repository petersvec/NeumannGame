#pragma once
#include "IBuilding.hpp"

namespace game
{
	class SpaceStation : public IBuilding
	{
	private:

	protected:

	public:
		SpaceStation(unsigned short hp,
					 ObjectType type,
					 const sf::Texture& texture,
					 engine::TilePtr location,
					 unsigned short ironCost,
					 unsigned short copperCost,
					 unsigned short siliconCost,
					 Ownership owner);

		virtual void update(std::shared_ptr<engine::Map> map,
							engine::ObjectManager objMan,
							bool toUpdate,
							engine::UnitFactoryPtr unitFactory,
							PlayerState& playerState,
							ObjectType objType) override;
		void makeWorker(engine::UnitFactoryPtr, engine::TilePtr);

		std::string getName() override;
	};
}