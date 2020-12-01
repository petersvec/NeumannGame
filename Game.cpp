#include "../include/Game.hpp"
#include <Map.hpp>

namespace engine
{
	
	void Game::initVariables()
	{
		this->window = nullptr;
	}

	void Game::initWindow()
	{
		this->videoMode = *new sf::VideoMode(1280, 720);
		this->window = new sf::RenderWindow(this->videoMode, "Neumann Game");
		rectangles.setPrimitiveType(sf::Quads);
		view1.setSize(sf::Vector2f(1280.f, 720.f));
		view1.setCenter(sf::Vector2f(100.f, 100.f));
		
		
		
	}

	void Game::initTiles()
	{	
		for (int i = 0; i < map.mapsize; i++) {
			for (int j = 0; j < map.mapsize; j++) {
				if ((i + j) % 3 == 0) map.tile[i][j].color = sf::Color::Red;

				else map.tile[i][j].color = sf::Color::Green;
			}
		}
	}

	void Game::initTile(size_t i, size_t j)
	{
		
	}

	Game::Game()
	{
		this->initVariables();
		this->initTiles();
		this->initWindow();
	}

	Game::~Game()
	{
		delete this->window;
	}

	const bool Game::isRunning() const
	{
		return this->window->isOpen();
	}

	void Game::pollEvents()
	{
		//Event polling
		while (this->window->pollEvent(event))
		{
			switch (this->event.type)
			{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::MouseWheelMoved:
				view1.zoom(1 + 0.1 * event.mouseWheel.delta);
			//	ZoomLevel += 1 + 0.1 * event.mouseWheel.delta;
				break;

			default:
				break;
			}
		}
	}

	void Game::update()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			view1.move(-1.f, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			view1.move(1.f, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			view1.move(0.f, -1.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			view1.move(0.f, 1.f);
		}

		this->pollEvents();
	}

	void Game::render()
	{
		
		float ZoomLevel = 1;
		int TileSize = 10;
		
		
		for (int i = 0; i < map.mapsize; i++) {
			for (int j = 0; j < map.mapsize; j++) {

				rectangles.append(sf::Vertex(sf::Vector2f(i * TileSize, j * TileSize), map.tile[i][j].color));
				rectangles.append(sf::Vertex(sf::Vector2f(i * TileSize + TileSize, j * TileSize), map.tile[i][j].color));
				rectangles.append(sf::Vertex(sf::Vector2f(i * TileSize + TileSize, j * TileSize + TileSize), map.tile[i][j].color));
				rectangles.append(sf::Vertex(sf::Vector2f(i * TileSize, j * TileSize + TileSize), map.tile[i][j].color));
				
			}
		}
		

		
		this->window->draw(rectangles);
		this->window->setView(view1);
		this->window->display();
		this->window->clear();
		rectangles.clear();
		
	}
}