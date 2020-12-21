#include "../include/Game.hpp"
#include <Map.hpp>
#include <iostream>

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
		

		view1.setSize(sf::Vector2f(1280.f, 720.f));
		view1.setCenter(sf::Vector2f(100.f, 100.f));
		rTex.create(1280, 800);
		
		
		
		
	}

	void Game::initTiles()
	{	
		
		
		for (int i = 0; i < map.mapsize; i++) {
			for (int j = 0; j < map.mapsize; j++) {
				
				if (!map.tile[i][j].texture.loadFromFile("3.jpg"))
				{
					std::cout << "error loading texture\n";
				}

				
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
				ZoomLevel = 1;
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
	//		std::cout << ZoomLevel;
			view1.move(-1.f * ZoomLevel, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			view1.move(1.f * ZoomLevel, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			view1.move(0.f, -1.f * ZoomLevel);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			view1.move(0.f, 1.f * ZoomLevel);
		}

		this->pollEvents();
	}

	void Game::render()
	{
		sf::Sprite spr;
		float ZoomLevel = 1;
		int TileSize = 100;
		
		
		for (int i = 0; i < map.mapsize; i++) {
			for (int j = 0; j < map.mapsize; j++) {
			//	if ((i + j) % 3 == 0) map.tile[i][j].shape.setFillColor(sf::Color::Red);
				map.tile[i][j].shape.setPosition(i * TileSize, j * TileSize);
				spr.setTexture(map.tile[i][j].texture);
				spr.setPosition(map.tile[i][j].shape.getPosition());
			//	spr.setColor(sf::Color(0, 255, 0));
				map.tile[i][j].shape.setTexture(&map.tile[i][j].texture);
			//	rTex.draw(spr);
				rTex.draw(map.tile[i][j].shape);

				
			}
		}

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