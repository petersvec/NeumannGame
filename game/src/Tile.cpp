#include "../include/Tile.hpp"
#include "../../engine/include/JsonParser.hpp"

namespace game
{
	Tile::Tile()
	{
		setMinerals(0);
		m_occupied = Ownership::Unoccupied;
		srand(static_cast<unsigned int>(time(nullptr)));
		m_type = TileType(rand() % 4);
		m_sprite.setScale(sf::Vector2f(1, 1));
	}

	Tile::Tile(unsigned char type)
	{
		m_occupied = Ownership::Unoccupied;
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

	void Tile::GenerateMinerals()
	{
		if (m_type != TileType::Void)
		{
			setMinerals(400 + rand() % 201);
		}
		else
		{
			setMinerals(0);
		}
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

	std::string Tile::getTypeString() const
	{
		if (m_type == TileType::Void)
		{
			return "Void";
		}
		else if (m_type == TileType::Copper)
		{
			return "Copper";
		}
		else if (m_type == TileType::Iron)
		{
			return "Iron";
		}
		else if (m_type == TileType::Silicon)
		{
			return "Silicon";
		}
	}

	sf::Sprite& Tile::getSprite()
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
		GenerateMinerals();
	}

	void Tile::setSprite(const sf::Texture& texture)
	{
		m_sprite.setTexture(texture);
		m_sprite.setTextureRect(sf::IntRect(0, 0, engine::config->getTileSize(), engine::config->getTileSize()));
	}

	Ownership Tile::getOccupied()
	{
		return m_occupied;
	}

	void Tile::setOccupied(game::Ownership ownership)
	{
		m_occupied = ownership;

		if (ownership == game::Ownership::Player1)
		{
			m_sprite.setColor(sf::Color(255, 0, 0, 230));
		}
		else
		{
			m_sprite.setColor(sf::Color(0, 0, 255, 230));
		}
	}

	void Tile::setPosition(float x, float y)
	{
		m_sprite.setPosition(x, y);
	}

	TileType Tile::getTileType() const
	{
		return m_type;
	}
}