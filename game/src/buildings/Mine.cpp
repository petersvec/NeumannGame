#include "../../include/buildings/Mine.hpp"

namespace game
{
	Mine::Mine(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		engine::TilePtr location,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost,
		game::Ownership owner)
		:
		IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost, owner },
		IObject{ hp, type, texture, location, owner }
	{}

	void Mine::update(std::shared_ptr<engine::Map> map,
					  engine::ObjectManager objMan,
					  bool toUpdate,
					  engine::UnitFactoryPtr unitFactory,
					  game::PlayerState& playerState,
					  game::ObjectType objType)
	{
		mine(playerState);
	}

	void Mine::mine(PlayerState& playerState)
	{
		unsigned minerals = getLocation()->getMinerals();
		playerState.updatePlayerBalances(minerals, minerals, minerals);
	}
}