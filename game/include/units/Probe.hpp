#pragma once
#include "IUnit.hpp"

namespace game
{
	class Probe : public IUnit
	{
	private:
		std::shared_ptr<engine::IObject> m_troop = nullptr;
		bool m_isLoaded = false;
		bool m_isDuplicating = false;
		unsigned char m_duplicateTime = 5;

	protected:

	public:
		Probe(unsigned short hp,
			  ObjectType type,
			  const sf::Texture& texture,
			  engine::TilePtr location,
			  unsigned char moveSpeed,
			  unsigned char range,
			  unsigned char attackDamage,
			  unsigned char armour,
			  Ownership owner);

		unsigned char getDuplicateTime();
		void setDuplicateTime(unsigned char);
		bool isLoaded();
		void setIsLoaded(bool);
		bool isDuplicating();
		void setDuplicating(bool);
		std::shared_ptr<engine::IObject> getTroop();
		void setTroop(std::shared_ptr<engine::IObject>);
		virtual void attack(std::shared_ptr<engine::IObject>, std::shared_ptr<engine::ObjectManager>) override;
		void duplicate(PlayerState&, PlayerState&, int*, std::shared_ptr<engine::ObjectManager>, std::shared_ptr<engine::Map>);
		void load(std::shared_ptr<engine::IObject>, std::shared_ptr<engine::ObjectManager>);
		void deploy(PlayerState&, PlayerState&, int*, std::shared_ptr<engine::ObjectManager>, std::shared_ptr<engine::Map>);
		std::string getName() override;
	};
}