#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "TileType.hpp"
#include "Ownership.hpp"
#include <time.h>
#include <SFML/System/Vector2.hpp>
#include <string>

namespace game
{
	class Tile
	{
	private:
		void GenerateMinerals();
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
		std::string getTypeString() const; 
		sf::Sprite &getSprite();
		sf::Vector2f getPosition() const;

		void setMinerals(unsigned short);
		void setType(unsigned char);
		void setSprite(const sf::Texture&);
		void setPosition(float, float);
		Ownership getOccupied();
		void setOccupied(Ownership);
		TileType getTileType() const;
	};
}