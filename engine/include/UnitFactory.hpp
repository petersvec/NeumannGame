#pragma once
#include "TextureHandler.hpp"
#include "../../game/include/buildings/AirBase.hpp"
#include "../../game/include/buildings/MilitaryBase.hpp"
#include "../../game/include/buildings/Mine.hpp"
#include "../../game/include/buildings/SpaceStation.hpp"
#include "../../game/include/buildings/Tower.hpp"
#include "../../game/include/units/Melee.hpp"
#include "../../game/include/units/Probe.hpp"
#include "../../game/include/units/Ranged.hpp"
#include "../../game/include/units/Worker.hpp"

namespace engine
{
	class UnitFactory;
	using UnitFactoryPtr = std::shared_ptr<UnitFactory>;
	extern UnitFactoryPtr unitFactory;

	class UnitFactory
	{
	private:

	protected:

	public:
		IObjectPtr create(game::ObjectType, TilePtr, game::Ownership);
	};
}