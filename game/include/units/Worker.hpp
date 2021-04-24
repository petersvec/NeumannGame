#pragma once
#include "IUnit.hpp"

namespace game
{
	class Worker : public IUnit
	{
	private:

	protected:

	public:
		Worker(unsigned short hp,
			   ObjectType type,
			   const sf::Texture& texture,
			   engine::TilePtr location,
			   unsigned char moveSpeed,
			   unsigned char range,
			   unsigned char attackDamage,
			   unsigned char armour,
			   Ownership owner);

		virtual void attack(std::shared_ptr<engine::IObject>, std::shared_ptr<engine::ObjectManager>) override;
		void build(PlayerState&, ObjectType, engine::TilePtr);
		std::string getName() override;
	};
}