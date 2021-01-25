#include <stdlib.h>
#include <time.h>
#include "../include/Tile.hpp"

namespace engine
{
	Tile::Tile()
	{
		srand(time(NULL));
		m_type = rand() % 7;
	}

	Tile::Tile(unsigned char type)
	{
		m_type = type;
	}

	Tile Tile::operator=(const unsigned char type)
	{
		return Tile(type);
	}

	bool Tile::operator==(const unsigned char type)
	{
		if (m_type == type)
		{
			return true;
		}
		return false;
	}

	unsigned char Tile::getType()
	{
		return m_type;
	}
}