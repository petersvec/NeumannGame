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
		virtual void build(game::PlayerState& playerState, engine::TilePtr location, std::shared_ptr<engine::ObjectManager> OM) override;
		virtual void workerBuild(game::PlayerState& playerState, engine::TilePtr location, std::shared_ptr<engine::ObjectManager> OM, game::ObjectType type) override;
		std::string getName() override;
	};
}