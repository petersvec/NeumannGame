#pragma once
#include <vector> 
#include "../include/Tile.hpp";
#define MAX_MAP_SIZE 10000

namespace engine
{
	class Map
	{
	private:
		//Private variables
		std::vector<std::vector<Tile> > map;

		//Private functions
		void updateMap();
		void destroyMap();

	public:
		//Constructors & destructor
		Map();
		~Map();

		//Public functions
		size_t getMapSize();
	};
}