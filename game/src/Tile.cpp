#include <stdlib.h>
#include <time.h>
#include "../include/Tile.hpp"

namespace game
{
	Tile::Tile()
	{
		setMinerals(0);
		m_occupied = game::Ownership::Unoccupied;
		srand(static_cast<unsigned int>(time(nullptr)));
		m_type = TileType(rand() % 4);
		m_sprite.setScale(sf::Vector2f(1, 1));
	}

	Tile::Tile(unsigned char type)
	{
		m_occupied = game::Ownership::Unoccupied;
		if (type > 0)
		{
			setMinerals(400 + rand() % 201);
		}
		else
		{
			setMinerals(0);
		}
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

	unsigned short Tile::getMinerals()
	{
		return m_minerals;
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

	void Tile::setMinerals(unsigned short minerals)
	{
		m_minerals = minerals;
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
	game::Ownership Tile::getOccupied()
	{
		return m_occupied;
	}
	void Tile::setOccupied(game::Ownership ownership)
	{
		m_occupied = ownership;

		if (ownership == game::Ownership::Player1)
		{
			m_sprite.setColor(sf::Color::Red);
		}
		else
		{
			m_sprite.setColor(sf::Color::Blue);
		}
	}

	void Tile::setPosition(float x, float y)
	{
		m_sprite.setPosition(x, y);
	}
}