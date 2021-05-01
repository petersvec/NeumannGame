#include "../../include/buildings/Mine.hpp"
#include "../../include/Tile.hpp"

namespace game
{
	Mine::Mine(unsigned short hp,
			   ObjectType type,
			   const sf::Texture& texture,
			   engine::TilePtr location,
			   unsigned short ironCost,
			   unsigned short copperCost,
			   unsigned short siliconCost,
			   Ownership owner)
			   :
			   IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost, owner },
			   IObject{ hp, type, texture, location, owner }
	{}

	bool Mine::update(std::shared_ptr<engine::Map> map,
					  std::shared_ptr<engine::ObjectManager> objMan,
					  PlayerState& playerState)
	{
		mine(playerState);
		return true;
	}

	void Mine::mine(PlayerState& playerState)
	{
		unsigned minerals = getLocation()->getMinerals();
		if (minerals == 0)
		{
			return;
		}
		
		if (minerals >= 100)
		{
			playerState.updatePlayerBalances(100, 100, 100);
			getLocation()->setMinerals(minerals - 100);
		}
		else
		{
			playerState.updatePlayerBalances(minerals, minerals, minerals);
			getLocation()->setMinerals(0);
		}
	}
  
	std::string Mine::getName()
	{
		return "Mine";
	}
}