#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "TileType.hpp"
#include "Ownership.hpp"
#include "../../engine/include/JsonParser.hpp"
#include <time.h>

namespace game
{
	class Tile
	{
	private:

	protected:
		unsigned short m_minerals;
		TileType m_type;
		sf::Sprite m_sprite;
		Ownership m_occupied;

	public:
		Tile();
		Tile(unsigned char);

		Tile operator = (const unsigned char);
		bool operator == (const unsigned char);

		unsigned short getMinerals();
		unsigned char getType();
		sf::Sprite getSprite();
		sf::Vector2f getPosition() const;

		void setMinerals(unsigned short);
		void setType(unsigned char);
		void setSprite(const sf::Texture&);
		void setPosition(float, float);
		Ownership getOccupied();
		void setOccupied(Ownership);
	};
}