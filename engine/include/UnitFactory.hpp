#pragma once

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