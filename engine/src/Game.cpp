#include <iostream>
#include "../include/Game.hpp"

namespace engine
{
	void Game::initVariables()
	{
		m_window = nullptr;
		Map m_gameMap(50, 50);
		MapGenerator* m_mapGenerator = new MapGenerator();
		m_mapGenerator->generateMap(m_gameMap, 50, 3);
		m_renderTexture.create(2000, 2000);
		m_renderMap.initMapTextures(m_gameMap);
	}

	void Game::initWindow()
	{
		m_videoMode = *new sf::VideoMode(1280, 720);
		m_window = new sf::RenderWindow(m_videoMode, "Neumann Game", sf::Style::Titlebar | sf::Style::Close);
		m_window->setFramerateLimit(60);
		m_view.setSize(sf::Vector2f(1280.f, 720.f));
	}

	Game::Game()
	{
		initVariables();
		initWindow();
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

			case sf::Event::MouseWheelMoved:
				if (ZoomLevel <= 2.8 && m_event.mouseWheel.delta == -1 || ZoomLevel > 0.2 && m_event.mouseWheel.delta == 1)
				{
					m_view.zoom(1 + 0.1 * -(m_event.mouseWheel.delta));
					ZoomLevel += (0.1 * -(m_event.mouseWheel.delta));
				}
				break;

			case sf::Event::MouseButtonPressed:
				pixelPos = sf::Mouse::getPosition(*m_window);
				worldPos = m_window->mapPixelToCoords(pixelPos);

				std::cout << worldPos.x;
				std::cout << " ";
				std::cout << worldPos.y;
				std::cout << '\n';
				break;

			default:
				break;
			}
		}
	}

	void Game::update()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (m_view.getCenter().x > -40)
			{
				m_view.move(-20.f, 0.f);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (m_view.getCenter().x < m_gameMap.getWidth() * tileSize + 40)
			{
				m_view.move(20.f, 0.f);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (m_view.getCenter().y > -40)
			{
				m_view.move(0.f, -20.f);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (m_view.getCenter().y < m_gameMap.getWidth() * tileSize + 40)
			{
				m_view.move(0.f, 20.f);
			}
		}

		pollEvents();
	}

	void Game::render()
	{
		m_renderTexture.clear();
		m_window->clear();
		
		m_renderMap.renderMap(m_gameMap, m_renderTexture);
		m_renderTexture.display();
		const sf::Texture& texture = m_renderTexture.getTexture();
		m_frame.setTexture(texture);
		m_window->draw(m_frame);
		m_window->setView(m_view);

		m_window->display();
	}
}