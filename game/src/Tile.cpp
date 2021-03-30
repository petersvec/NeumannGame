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

	sf::Vector2f Tile::getPosition() const
	{
		return m_sprite.getPosition();
	}

	unsigned char Tile::getType()
	{
		return (unsigned char)m_type;
	}

	sf::Sprite Tile::getSprite()
	{
		return m_sprite;
	}

	void Tile::setType(unsigned char type)
	{
		m_type = (TileType)type;
	}

	void Tile::setSprite(const sf::Texture& texture)
	{
		m_sprite.setTexture(texture);
		m_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));  //a.k.a tileSize
	}
	bool Tile::getOccupied()
	{
		return occupied;
	}
	void Tile::setOccupied(bool value)
	{
		occupied = value;
	}

	void Tile::setPosition(float x, float y)
	{
		m_sprite.setPosition(x, y);
	}
}