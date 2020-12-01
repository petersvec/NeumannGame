#pragma once
#include <SFML/Graphics.hpp>
#include "../include/MapGenerator.hpp"

namespace engine
{
	class Game
	{
	private:
		sf::RenderWindow* m_window;
		sf::Event m_event;
		Map m_gameMap;
		MapGenerator m_mapGenerator;

		void initVariables();
		void initWindow();

	public:
		Game();
		virtual ~Game();

		const bool isRunning() const;
		void pollEvents();
		void update();
		void render();
	};
}