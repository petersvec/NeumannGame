#pragma once
#include <time.h>
#include <random>
#include "Map.hpp"

namespace engine
{
	class MapGenerator
	{
	private:
		void setPlanet(Map*, unsigned short, unsigned short, unsigned char, unsigned char);

	public:
		void generateMap(Map*, unsigned short, unsigned char);
	};
}