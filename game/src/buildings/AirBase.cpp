#include "../../include/buildings/AirBase.hpp"

namespace game
{
	AirBase::AirBase(game::ObjectType type,
		const sf::Texture& texture,
		unsigned short ironCost,
		unsigned short copperCost,
		unsigned short siliconCost)
		:
		IBuilding{ type, texture, ironCost, copperCost, siliconCost }
	{}
}