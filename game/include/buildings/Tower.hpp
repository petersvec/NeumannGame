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
			  ObjectType type,
			  const sf::Texture& texture,
			  engine::TilePtr location,
			  unsigned char moveSpeed,
			  unsigned char attackDamage,
			  unsigned char armour,
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
		virtual void attack(engine::IObjectPtr object) override;
		virtual void move(engine::TilePtr, unsigned char, PlayerState&) override {}

		std::string getName() override;
	};
}