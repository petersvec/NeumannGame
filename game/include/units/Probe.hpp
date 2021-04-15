#pragma once
#include "IUnit.hpp"

namespace game
{
	class Probe : public IUnit
	{
	private:

	protected:
		engine::IObjectPtr m_troop = nullptr;
		bool m_loaded = false;
		unsigned char m_duplicateTime = 5;

	public:
		Probe(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			engine::TilePtr location,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour,
			game::Ownership owner);

		virtual void update(std::shared_ptr<engine::Map> map,
							engine::ObjectManager objMan,
							bool toUpdate,
							engine::UnitFactoryPtr unitFactory,
							game::PlayerState& playerState,
							game::ObjectType objType) override;
		virtual void attack(engine::IObjectPtr object) override;
		void duplicate(engine::UnitFactoryPtr unitFactory, engine::ObjectManager objMan, std::shared_ptr<engine::Map> map);
		void load(engine::IObjectPtr troop);
		void deploy();
	};
}