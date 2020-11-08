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
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
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

	}
}