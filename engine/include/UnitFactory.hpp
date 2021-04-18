#pragma once
#include <memory>
#include "../../game/include/ObjectType.hpp"
#include "../../game/include/Ownership.hpp"
#include "Map.hpp"

namespace engine
{
	class UnitFactory;
	using UnitFactoryPtr = std::shared_ptr<UnitFactory>;
	extern UnitFactoryPtr unitFactory;

	class IObject;

	class UnitFactory
	{
	private:

	protected:

	public:
		std::shared_ptr<IObject> create(game::ObjectType, TilePtr, game::Ownership);
	};
}