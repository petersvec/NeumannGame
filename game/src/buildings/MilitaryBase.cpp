#include "../../include/buildings/MilitaryBase.hpp"

namespace game
{
	MilitaryBase::MilitaryBase(unsigned short hp,
		game::ObjectType type,
		const sf::Texture& texture,
		TilePtr location,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost,
		Player owner)
		:
		IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost, owner },
		IObject{ hp, type, texture, location, owner }
	{}

	std::string MilitaryBase::getName()
	{
		return "Military Base";
	}

	
}