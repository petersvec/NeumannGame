#include "../include/MapGenerator.hpp"

namespace engine
{
	MapGenerator::MapGenerator()
	{
		this->map = new Map();
	}
	
	MapGenerator::~MapGenerator()
	{
		this->map->~Map();
	}
}