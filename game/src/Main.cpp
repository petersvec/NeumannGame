#include <SFML/Graphics.hpp>
//#include "../include/Game.hpp"
#include <iostream>
#include "../../engine/include/Game.hpp"

int main(void)
{
	//Init game engine
	engine::Game game;

	//Game loop
	while (game.isRunning())
	{
		//----------UPDATE----------//
		game.update();

		//----------RENDER----------//
		game.render();

	}
	//End of appliecation
	return 0;
}