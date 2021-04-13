#pragma once
#include "IBuilding.hpp"
#include "../units/IUnit.hpp"

namespace game
{
	class Tower : public IBuilding, public game::IUnit
	{
	private:

	protected:

	public:
		Tower(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			engine::TilePtr location,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour,
			unsigned short ironCost,
			unsigned short copperCost, 
			unsigned short siliconCost,
			game::Ownership owner);

		virtual void update(std::shared_ptr<engine::Map> map,
							engine::ObjectManager objMan,
							bool toUpdate,
							engine::UnitFactoryPtr unitFactory,
							game::PlayerState playerState1) override;
		virtual void attack(engine::IObjectPtr object);
		virtual void move(engine::TilePtr tile, unsigned char tileSize) {}
	};
}