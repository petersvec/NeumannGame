#include <iostream>
#include "../include/Game.hpp"
#include "../include/Shader.hpp"

namespace engine
{
	void Game::initVariables()
	{
		m_window = nullptr;
		m_gameMap = new Map(200, 200);
		MapGenerator* m_mapGenerator = new MapGenerator();
		m_mapGenerator->generateMap(m_gameMap, 50, 3);
		m_renderTexture.create(m_gameMap->getWidth()*tileSize, m_gameMap->getHeight() * tileSize);
		m_renderMap.initMapTextures(*m_gameMap);
		tileText.setString("0");
		m_guiRectangle.setPosition(0, 620);
		m_guiRectangle.setSize(sf::Vector2f(1280, 100));
		m_guiRectangle.setFillColor(sf::Color::Blue);
		testOM.createPO(10, 10, 1, 1);
		testOM.createPO(15, 15, 2, 1);

		testPO=testOM.findUnit(15 * 50, 15 * 50);
	
		
		
	}

	void Game::initWindow()
	{
		m_videoMode = *new sf::VideoMode(1280, 720);
		m_window = new sf::RenderWindow(m_videoMode, "Neumann Game", sf::Style::Titlebar | sf::Style::Close);
		m_window->setFramerateLimit(60);
		m_view.setSize(sf::Vector2f(1280.f, 720.f));
		defaultView.setSize(sf::Vector2f(1280.f, 720.f));
		defaultView.setCenter(1280/2, 720/2);
		
		//Shader shader;
		//shader.doStuff();
		
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

	void Game::clickMap(int x, int y)
	{
		if (x >= 0 && y >= 0 && x < tileSize * (m_gameMap->getWidth()) && y < tileSize * m_gameMap->getHeight())
		{
			
			
			
			char c = (unsigned char)m_gameMap->getTile(x/tileSize, y/tileSize)->getType();
			str = std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(c);
			std::cout << m_gameMap->getTile(x / tileSize, y / tileSize)->getType();

			// m_gameMap->getTile(x, y);


			setDisplayText(&tileText, str);
		}
		
	}

	void Game::setDisplayText(sf::Text *text, sf::String str) {

		text->setString(str);
		text->setCharacterSize(40); // in pixels
		text->setFillColor(sf::Color::Red);
		text->setPosition(0, 640);
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
				if (ZoomLevel <= 3.0 && m_event.mouseWheel.delta == -1 || ZoomLevel > 0.2 && m_event.mouseWheel.delta == 1)
				{
					m_view.zoom(1 + 0.1 * -(m_event.mouseWheel.delta));
					ZoomLevel += (0.1 * -(m_event.mouseWheel.delta));
				}
				break;

			case sf::Event::MouseButtonPressed:
				pixelPos = sf::Mouse::getPosition(*m_window);
				worldPos = m_window->mapPixelToCoords(pixelPos);

/*
				std::cout << pixelPos.x;
				std::cout << " ";
				std::cout << pixelPos.y;
				std::cout << " ";
				std::cout << "window";
				std::cout << '\n';
*/
				std::cout << worldPos.x;
				std::cout << " ";
				std::cout << worldPos.y;
				std::cout << " ";
				std::cout << "map";
				std::cout << '\n';
				std::cout << playerActive;
				std::cout << " player turn\n";

				//if(pixelPos.y < GuiHeight)
				clickMap(worldPos.x, worldPos.y);

				/*
				else
				{
				clickGui(pixelPos.x, pixelPos.y);
				}
				*/
				
				break;

				case sf::Event::KeyPressed:
					if (m_event.key.code == sf::Keyboard::Space)
					{
						if (playerActive == 1)
						{
							playerActive = 2;
						}
						else
						{
							playerActive = 1;
						}
						std::cout << "Player switched\n";
					}
					
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
			if (m_view.getCenter().x < m_gameMap->getWidth() * tileSize + 40)
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
			if (m_view.getCenter().y < m_gameMap->getWidth() * tileSize + 40)
			{
				m_view.move(0.f, 20.f);
			}
		}

		pollEvents();
	}

	void Game::render()
	{
		sf::Font font;
		font.loadFromFile("data/fonts/OpenSans-Bold.ttf");
		tileText.setFont(font);
		m_window->clear();


		if (changed == 1) 
		{
			m_renderTexture.clear();
			m_renderMap.renderMap(*m_gameMap, m_renderTexture);
			changed=0;
		}
		
		m_renderTexture.display();
		
		const sf::Texture& texture = m_renderTexture.getTexture();
		m_frame.setTexture(texture);
		m_window->setView(m_view);
		m_window->draw(m_frame);
		testOM.drawAll(m_window);
		
		m_window->setView(defaultView);
		m_window->draw(m_guiRectangle);
		m_window->draw(tileText);
		m_window->setView(m_view);

		m_window->display();

		
	}
}