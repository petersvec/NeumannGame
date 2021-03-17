#pragma once
#include "../include/IObject.hpp"
#include "../../game/include/ObjectType.hpp"
#include "../../game/include/units/Meele.hpp"
#include "../../game/include/units/Probe.hpp"
#include "../../game/include/units/Ranged.hpp"
#include "../../game/include/units/Worker.hpp"
#include "../../game/include/buildings/AirBase.hpp"
#include "../../game/include/buildings/MilitaryBase.hpp"
#include "../../game/include/buildings/Mine.hpp"
#include "../../game/include/buildings/SpaceStation.hpp"
#include "../../game/include/buildings/Tower.hpp"

namespace engine
{
	class Factory
	{
	private:

	protected:

	public:
		IObject getObject(game::ObjectType objType);
	};
}