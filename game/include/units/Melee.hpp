#pragma once
#include "IUnit.hpp"

namespace game
{
	class Melee : public IUnit
	{
	private:

	protected:

	public:
		Melee(unsigned short hp,
			  ObjectType type,
			  const sf::Texture& texture,
			  engine::TilePtr location,
			  unsigned char moveSpeed,
			  unsigned char range,
			  unsigned char attackDamage,
		 	  unsigned char armour,
			  Ownership owner);

		virtual void attack(std::shared_ptr<engine::IObject>, std::shared_ptr<engine::ObjectManager>) override;
		std::string getName() override;
    };
}