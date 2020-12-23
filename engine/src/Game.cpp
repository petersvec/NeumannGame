#include "../include/Game.hpp"
#include <iostream>

namespace engine
{
	void Game::initVariables()
	{
		m_window = nullptr;
		Map m_gameMap(5000, 5000);
		MapGenerator* m_mapGenerator = new MapGenerator();
		m_mapGenerator->generateMap(m_gameMap);
	}

	void Game::initWindow()
	{
		m_window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Neumann Game", sf::Style::Titlebar | sf::Style::Close);
		m_window->setFramerateLimit(144);
	}

	Game::Game()
		{
		initVariables();
		initWindow();

		m_mapGenerator.generateMap(m_gameMap);
		std::cout << m_gameMap.getTile(10, 10).get()->getType();
	}

	Game::~Game()
	{
		delete m_window;
	}

	const bool Game::isRunning() const
	{
		return m_window->isOpen();
	}

	void Game::pollEvents()
	{
		while (m_window->pollEvent(m_event))
		{
			switch (m_event.type)
			{
			case sf::Event::Closed:
				m_window->close();
				break;
			default:
				break;
			}
		}
	}

	void Game::update()
	{
		pollEvents();
	}

	void Game::render()
	{
		m_window->clear();
		
		//Draw the game
		//TODOOOOOOOOOOOOOOOOOO
		
		m_window->display();
	}
}