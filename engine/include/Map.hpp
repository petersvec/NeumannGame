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
		std::vector<std::vector<Tile*>> map;

		//Private functions
		void updateMap();
		void destroyMap();
		bool isLinked(size_t i, size_t j, unsigned char type);

	public:
		//Constructors & destructor
		Map();
		Map(const Map& m);
		~Map();

		//Operators
		Map& operator=(const Map& m) {};

		//Public functions
		size_t getMapSize();
		std::vector<std::vector<Tile>> getMap();
	};
}