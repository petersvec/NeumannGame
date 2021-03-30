#pragma once

#include <memory>
#include <SFML\Graphics\Texture.hpp>

#include "../../game/include/units/IUnit.hpp"
#include "../../game/include/ObjectType.hpp"
#include "../../game/include/units/Melee.hpp"
#include "../../game/include/units/Probe.hpp"
#include "../../game/include/units/Ranged.hpp"
#include "../../game/include/units/Worker.hpp"
#include "../../game/include/buildings/AirBase.hpp"
#include "../../game/include/buildings/MilitaryBase.hpp"
#include "../../game/include/buildings/Mine.hpp"
#include "../../game/include/buildings/SpaceStation.hpp"
#include "../../game/include/buildings/Tower.hpp"
#include "Utilities.hpp"

namespace engine
{
	class UnitFactory;
	using UnitFactoryPtr = std::unique_ptr<UnitFactory>;
	extern UnitFactoryPtr unitFactory;

	class UnitFactory
	{
	private:

	protected:

	public:
		game::IUnitPtr create(game::ObjectType objType, TilePtr location, game::Player owner);
	};
}