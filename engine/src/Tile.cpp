#include "../include/Tile.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

namespace engine
{
	Tile::Tile()
	{
		srand(time(NULL));
		this->type = rand() % 2;
	}

	bool Tile::operator==(const unsigned char type)
	{
		if (this->type == type)
		{
			return true;
		}
		return false;
	}
}