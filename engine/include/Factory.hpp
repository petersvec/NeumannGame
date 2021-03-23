#pragma once
#include <memory>
#include "../include/IObject.hpp"
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
using IObjectPtr = std::shared_ptr<engine::IObject>;

namespace engine
{
	class Factory
	{
	private:

	protected:

	public:
		IObjectPtr getObject(game::ObjectType objType);
	};
}