#pragma once
#include "../../engine/include/IObject.hpp"
#include "TileType.hpp"

namespace game
{
	class Tile : public engine::IObject
	{
	private:

	protected:
		TileType m_type;

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