#pragma once

namespace engine
{
	class Tile
	{
	private:
		//Private variables
		unsigned char type;	//type of the Tile: 0-void, 1-planet of player one, 2-planet of player 2, 3-resources on the planet, 4-resources on the planet of the player 1, 5-resources on the planet of the player 2
	
	public:
		//Constructors & destructor
		Tile();
		bool operator == (const unsigned char type);

		//Public functions
	};
}