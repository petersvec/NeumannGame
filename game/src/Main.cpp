#include <SFML/Graphics.hpp>
#include "../../engine/include/Game.hpp/"

int main(void)
{
	engine::Game* game = new engine::Game();

	while (game->isRunning())
	{
		game->update();
		game->render();
	}

	return 0;
}