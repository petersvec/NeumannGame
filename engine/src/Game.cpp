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
		//view1.setCenter(sf::Vector2f(100.f, 100.f));

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
		//rTex.create(map.mapsize*tileSize, map.mapsize*tileSize);
		rTex.create(2000, 2000);
		RenderMap.InitMapTextures(map);
		std::cout << "init done\n";
	}

	void Game::initTile(size_t i, size_t j)
	{
		
	}

	Tile Game::getTile(int x, int y)
	{
		if (x >= 0 && y >= 0 && x <= tileSize * map.mapsize && y <= tileSize * map.mapsize)
		{
			return map.tile[x / tileSize][y / tileSize];
		}
		else 
		{
			return NULL;
		}
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
			case sf::Event::MouseWheelMoved:  //Zoom
				if (ZoomLevel <= 2.8 && event.mouseWheel.delta==-1 || ZoomLevel > 0.2 && event.mouseWheel.delta ==1 )
				{
					view1.zoom(1 + 0.1 * -(event.mouseWheel.delta));
					ZoomLevel +=  ( 0.1 * -(event.mouseWheel.delta));
				}
				break;
			case sf::Event::MouseButtonPressed:  //Click coordinates
				
				pixelPos = sf::Mouse::getPosition(*window);
				worldPos = window->mapPixelToCoords(pixelPos);

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
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))  //Move view - map
		{
			if (view1.getCenter().x > -40){
				view1.move(-20.f, 0.f);
			}	
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (view1.getCenter().x < map.mapsize*tileSize + 40) {
				view1.move(20.f, 0.f);
			}	
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (view1.getCenter().y > -40) {
				view1.move(0.f, -20.f);
			}	
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (view1.getCenter().y < map.mapsize*tileSize + 40) {
				view1.move(0.f, 20.f);
			}	
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