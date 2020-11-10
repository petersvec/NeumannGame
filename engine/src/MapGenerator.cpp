#include "../include/MapGenerator.hpp"

namespace engine
{	
	MapGenerator::MapGenerator()
	{
		this->generateMap();
	}
	
	MapGenerator::~MapGenerator()
	{
		delete &this->map;
	}
	
	Map MapGenerator::generateMap()
	{
		this->map = Map();
	}
}