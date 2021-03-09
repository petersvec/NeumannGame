#pragma once
#include "IUnit.hpp"
#include "TileType.hpp"

namespace game
{
	class Tile : public IObject
	{
	private:

	protected:
		TileType m_type;
		//IUnit array[] = vsetky jednotky ktore sa nachadzaju na Tile

	public:
		Tile();
		Tile(unsigned char type);

		Tile operator = (const unsigned char);
		bool operator == (const unsigned char);

		unsigned char getType();

		void setType(unsigned char type);
		void setPosition(float, float);
	};
}