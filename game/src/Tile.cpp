#include <stdlib.h>
#include <time.h>
#include "../include/Tile.hpp"

namespace game
{
	Tile::Tile()
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		m_type = TileType(rand() % 4);
		m_sprite.setScale(sf::Vector2f(1, 1));
	}

	Tile::Tile(unsigned char type)
	{
		m_type = TileType(type);
		m_sprite.setScale(sf::Vector2f(1, 1));
	}

	Tile Tile::operator=(const unsigned char type)
	{
		return Tile(type);
	}

	bool Tile::operator==(const unsigned char type)
	{
		if (unsigned char(m_type) == type)
		{
			return true;
		}
		return false;
	}

	unsigned char Tile::getType()
	{
		return (unsigned char)m_type;
	}

	void Tile::setType(unsigned char type)
	{
		m_type = (TileType)type;
	}

	void Tile::setPosition(float x, float y)
	{
		m_sprite.setPosition(x, y);
	}
}