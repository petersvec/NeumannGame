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
        
		virtual bool update(PlayerState&, PlayerState&, int*, std::shared_ptr<engine::Map>, std::shared_ptr<engine::ObjectManager>) override;
		virtual void attack(std::shared_ptr<engine::IObject>, std::shared_ptr<engine::ObjectManager>) override;
		virtual void move(engine::TilePtr, PlayerState&, PlayerState&, int*) override {};

		std::string getName() override;
	};
}