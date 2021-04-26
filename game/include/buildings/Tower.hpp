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
			  unsigned char range,
			  unsigned char attackDamage,
			  unsigned char armour,
			  unsigned short ironCost,
			  unsigned short copperCost, 
			  unsigned short siliconCost,
			  Ownership owner);
        
		virtual void update(std::shared_ptr<engine::Map> map,
							std::shared_ptr<engine::ObjectManager> objMan,
							bool toUpdate,
							PlayerState& playerState) override;
		virtual void attack(std::shared_ptr<engine::IObject>, std::shared_ptr<engine::ObjectManager>) override;
		virtual void move(engine::TilePtr, PlayerState&, PlayerState&, int*) override {};

		std::string getName() override;
	};
}