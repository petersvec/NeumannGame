#include "Game.hpp"

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

	void Game::update()
	{

	}

	void Game::render()
	{

	}
}