#pragma once
#include <SFML/Graphics.hpp>

namespace engine
{
	class Game
	{
	private:
		//Variables
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
		void update();
		void render();
	};
}