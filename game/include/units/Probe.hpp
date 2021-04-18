#pragma once
#include "IUnit.hpp"

namespace game
{
	class Probe : public IUnit
	{
	private:

	protected:
		std::shared_ptr<engine::IObject> m_troop = nullptr;
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
							std::shared_ptr<engine::ObjectManager> objMan,
							bool toUpdate,
							PlayerState& playerState,
							ObjectType objType) override;
		virtual void attack(std::shared_ptr<engine::IObject> object) override;
		void duplicate(std::shared_ptr<engine::ObjectManager>, std::shared_ptr<engine::Map>);
		void load(std::shared_ptr<engine::IObject>);
		void deploy();
		std::string getName() override;
	};
}