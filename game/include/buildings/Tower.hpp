#pragma once
#include "IBuilding.hpp"
#include "../units/IUnit.hpp"

namespace game
{
	class Tower : public IBuilding, public IUnit
	{
	private:

	protected:

	public:
		Tower(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			TilePtr location,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour,
			unsigned short ironCost,
			unsigned short copperCost, 
			unsigned short siliconCost,
			Player owner);

		virtual void attack(engine::IObjectPtr object);
		virtual void move(engine::TilePtr object) {};

		void update(std::shared_ptr<engine::Map> map);
	};
}