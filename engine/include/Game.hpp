#pragma once
#include <SFML/Graphics.hpp>

namespace engine
{
	class Game
	{
	private:
		//Private variables
		//Window
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event event;

		//Private functions
		void initVariables();
		void initWindow();

	public:
		//Constructors & destructor
		Game();
		virtual ~Game();

		//Accessors
		const bool isRunning() const;

		//Public functions
		void pollEvents();
		void update();
		void render();
	};
}