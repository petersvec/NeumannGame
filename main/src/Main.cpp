#include "../include/Main.hpp"

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
	//End of application
	return 0;
}