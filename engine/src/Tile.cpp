#include "../include/Tile.hpp"
#include <stdlib.h>

namespace engine
{
	Tile::Tile()
	{
		 value = rand() % (1) + 2;
	}
}
