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
			  ObjectType type,
			  const sf::Texture& texture,
			  engine::TilePtr location,
			  unsigned char moveSpeed,
			  unsigned char attackDamage,
			  unsigned char armour,
			  Ownership owner);

		virtual void update(std::shared_ptr<engine::Map> map,
							engine::ObjectManager objMan,
							bool toUpdate,
							engine::UnitFactoryPtr unitFactory,
							PlayerState& playerState,
							ObjectType objType) override;
		virtual void attack(engine::IObjectPtr object) override;
		void duplicate(engine::UnitFactoryPtr, engine::ObjectManager, std::shared_ptr<engine::Map>);
		void load(engine::IObjectPtr);
		void deploy();
	};
}