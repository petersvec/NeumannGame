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

		virtual void update(std::shared_ptr<engine::Map> map,
			std::shared_ptr<engine::ObjectManager> objMan,
			bool toUpdate,
			PlayerState& playerState,
			ObjectType objType) override;
		void build(engine::TilePtr, engine::ObjectManager*);

		std::string getName() override;
	};
}