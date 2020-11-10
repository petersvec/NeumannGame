#pragma once
#include "Map.hpp"

namespace engine
{
	class MapGenerator
	{
	private:
		//Private variables
		Map* map;

	public:
		//Constructors & destructor
		MapGenerator();
		~MapGenerator();

		//Public functions
		Map generateMap();
		Map getMap();
	};
}