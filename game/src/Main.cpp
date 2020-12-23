#include <SFML/Graphics.hpp>
#include "/Users/andre/Documents/Programovanie/Git/NeumannGame/engine/include/Game.hpp"

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