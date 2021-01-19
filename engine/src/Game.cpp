#include "../include/Game.hpp"
#include "../include/Map.hpp"
#include <iostream>
#include "../include/TextureHandler.hpp"


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
		this->window->setFramerateLimit(60);
		view1.setSize(sf::Vector2f(1280.f, 720.f));
		view1.setCenter(sf::Vector2f(100.f, 100.f));
		rTex.create(2000, 2000);
	}

	void Game::initTiles()
	{	
		map.tile = new Tile*[map.mapsize];
		for (int i = 0; i < map.mapsize; i++) 
		{
			map.tile[i] = new Tile[map.mapsize];
		}
		for (int i = 0; i < map.mapsize; i++)
		{
			for (int j = 0; j < map.mapsize; j++)
			{
				map.tile[i][j].sprite.setPosition(i * tileSize, j * tileSize);
			}
		}
		RenderMap.InitMapTextures(map);
		std::cout << "init done\n";
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
				if (ZoomLevel <= 3 && event.mouseWheel.delta==-1 || ZoomLevel > 0 && event.mouseWheel.delta ==1 )
				{
					view1.zoom(1 + 0.1 * -(event.mouseWheel.delta));
					ZoomLevel +=  ( 0.1 * -(event.mouseWheel.delta));
				}
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
			view1.move(-10.f , 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			view1.move(10.f , 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			view1.move(0.f, -10.f );
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			view1.move(0.f, 10.f );
		}

		this->pollEvents();
	}

	void Game::render()
	{
		RenderMap.RenderM(map, rTex);

		rTex.display();
		const sf::Texture& texture = rTex.getTexture();
		sprite.setTexture(texture);
		
		this->window->draw(sprite);
		this->window->setView(view1);
		this->window->display();
		this->window->clear();
		rTex.clear();	
	}
}