#include "../include/Game.hpp"

namespace engine
{
	void Game::initVariables()
	{
		this->window = nullptr;
	}

	void Game::initWindow()
	{
		this->videoMode = *new sf::VideoMode(1280, 720);
		this->window = new sf::RenderWindow(this->videoMode, "Neumann Game", sf::Style::Titlebar | sf::Style::Close);
	}

	Game::Game()
	{
		this->initVariables();
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
		while (this->window->pollEvent(this->event))
		{
			switch (this->event.type)
			{
			case sf::Event::Closed:
				this->window->close();
				break;
			default:
				break;
			}
		}
	}

	void Game::update()
	{
		this->pollEvents();
	}

	void Game::render()
	{
		/*
			Renders the game objects.
				- clear old frame
				- render objects
				- display frame in window
		*/
		this->window->clear();
		
		//Draw the game
		//TODOOOOOOOOOOOOOOOOOO
		
		this->window->display();
	}
}