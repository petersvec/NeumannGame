#include "../include/Game.hpp"
#include <SFML/Window/Mouse.hpp>

namespace engine
{
	void Game::initVariables()
	{
		if (!config->setGameConfig("config.json", "Settings"))
		{
			exit(-555);
		}

		m_window = nullptr;
		m_gameMap = new Map(config->getMapHeight(), config->getMapWidth());
		MapGenerator* m_mapGenerator = new MapGenerator();
		m_mapGenerator->generateMap(m_gameMap, config->getNumberOfPlanets(), config->getMaxRadiusOfPlanet());
		m_renderTexture.create(m_gameMap->getWidth() * tileSize, m_gameMap->getHeight() * tileSize);
		textures->LoadTextures();
		m_renderMap.initMapTextures(*m_gameMap);
		ActivePlayerText.setString("Player 1");
		ActivePlayerText.setPosition(1100, 640);
		ActivePlayerText.setCharacterSize(40);
		ActivePlayerText.setFillColor(sf::Color::Red);
		ActivePlayerText.setFont(m_gui.GetFont());
		m_guiRectangle.setPosition(0, 620);
		m_guiRectangle.setSize(sf::Vector2f(1280, 100));
		m_guiRectangle.setFillColor(sf::Color(41, 43, 44));

		selectedMapTile.setFillColor(sf::Color::Transparent);
		selectedMapTile.setOutlineColor(sf::Color::Green);
		selectedMapTile.setOutlineThickness(3);
		selectedMapTile.setPosition(0, 0);
		selectedMapTile.setSize(sf::Vector2f(tileSize, tileSize));
	
		auto unit_1 = unitFactory->create(game::ObjectType::Melee, m_gameMap->getTile(10, 10), game::Ownership::Player1);
		auto unit_2 = unitFactory->create(game::ObjectType::Melee, m_gameMap->getTile(10, 11), game::Ownership::Player2);

		auto building_1 = unitFactory->create(game::ObjectType::MilitaryBase, m_gameMap->getTile(1, 1), game::Ownership::Player1);
		auto building_2 = unitFactory->create(game::ObjectType::Tower, m_gameMap->getTile(3, 3), game::Ownership::Player2);

		testOM.addUnit(unit_1);
		testOM.addUnit(unit_2);
		testOM.addUnit(building_1);
		testOM.addUnit(building_2);

		clickMap(0, 0);

		m_cursor.setTexture(*textures->getTexture("cursor"));

		m_gui.SetPlayerState(player1State);
	}

	void Game::initWindow()
	{
		m_videoMode = *new sf::VideoMode(1280, 720);
		m_window = new sf::RenderWindow(m_videoMode, "Neumann Game", sf::Style::Titlebar | sf::Style::Close);
		m_window->setFramerateLimit(60);
		m_view.setSize(sf::Vector2f(1280.f, 720.f));
		defaultView.setSize(sf::Vector2f(1280.f, 720.f));
		defaultView.setCenter(1280/2, 720/2);
		m_window->setMouseCursorVisible(false);
		
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
			x = x / tileSize;
			y = y / tileSize;
			
			m_gui.text.setString("");
			testPO=testOM.findUnit(x * tileSize, y * tileSize, activePlayer);
			
			if (testPO != nullptr)
			{
				m_gui.LoadObject(testPO);
				unitIsSelected = true;
			}
			else
			{
				unitIsSelected = false;
			}

			auto tile = m_gameMap->getTile(x, y);
			str = "X: " + std::to_string(x) + "\nY: " + std::to_string(y) + "\nType: " + tile->getTypeString() + "\nMinerals: " + std::to_string(tile->getMinerals());
			setDisplayText(&tileText, str);
			setClickedTile(x, y, &selectedMapTile);
			//return m_gameMap->getTile(x, y);
		}
		
	}
	void Game::setClickedTile(int x, int y, sf::RectangleShape* rs)
	{
		rs->setPosition(x*tileSize, y*tileSize);
	}

	void Game::setDisplayText(sf::Text *text, sf::String str) {

		// select the font
		

		// set the string to display
		text->setString(str);
		text->setCharacterSize(20); // in pixels
		text->setFillColor(sf::Color::White);
		text->setPosition(0, 0);
		text->setFont(m_gui.GetFont());
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

			case sf::Event::MouseWheelMoved:					//zoom
				if (ZoomLevel <= 3.0 && m_event.mouseWheel.delta == -1 || ZoomLevel > 0.2 && m_event.mouseWheel.delta == 1)
				{
					m_view.zoom(1 + 0.1f * -(m_event.mouseWheel.delta));
					ZoomLevel += (0.1f * -(m_event.mouseWheel.delta));
				}
				break;

			case sf::Event::MouseButtonPressed:				//click
				if (m_event.mouseButton.button == sf::Mouse::Left) {


					pixelPos = sf::Mouse::getPosition(*m_window);
					worldPos = m_window->mapPixelToCoords(pixelPos);

					if (pixelPos.y < 620) {
						clickMap(worldPos.x, worldPos.y);
					}
					/*
					else
					{
					clickGui(pixelPos.x, pixelPos.y);
					}
					*/
				}
				

				if (m_event.mouseButton.button == sf::Mouse::Right)
				{
					if (unitIsSelected) {
						pixelPos = sf::Mouse::getPosition(*m_window);
						worldPos = m_window->mapPixelToCoords(pixelPos);
						if (testPO->getIsBuilding() == false  && testPO->getOwner() == activePlayer)
						{
							testPO->setPosition(sf::Vector2u(worldPos.x / tileSize, worldPos.y / tileSize));
							
							int posx = worldPos.x / tileSize;		//problem s celociselnym delenim
							int posy = worldPos.y / tileSize;
							selectedMapTile.setPosition(posx*tileSize, posy*tileSize);

							// obsadzovanie (do samostatnej funkcie)
							//////
							auto tile = m_gameMap->getTile(posx, posy);
							if (tile->getTileType() != game::TileType::Void)
							{
								tile->setOccupied(activePlayer);
								if (activePlayer == game::Ownership::Player1) player1State.updateLand(1);
								if (activePlayer == game::Ownership::Player2) player2State.updateLand(1);
								changed = 1; // <- prekreslit treba mapu ofc
							}
							//////

							if (activePlayer == game::Ownership::Player1)
							{
								unitIsSelected = false;
								testPO = nullptr;
								activePlayer = game::Ownership::Player2;
								ActivePlayerText.setString("Player 2");
								ActivePlayerText.setFillColor(sf::Color::Blue);
								m_gui.SetPlayerState(player2State);
							}
							else
							{
								unitIsSelected = false;
								testPO = nullptr;
								activePlayer = game::Ownership::Player1;
								ActivePlayerText.setString("Player 1");
								ActivePlayerText.setFillColor(sf::Color::Red);
								m_gui.SetPlayerState(player1State);
							}
						}
					}
				}
				break;

				case sf::Event::KeyPressed:							//key pressed
					if (m_event.key.code == sf::Keyboard::Space)	//space pressed switch player
					{
						if (activePlayer == game::Ownership::Player1)
						{
							unitIsSelected = false;
							testPO = nullptr;
							activePlayer = game::Ownership::Player2;
							ActivePlayerText.setString("Player 2");
						}
						else
						{
							unitIsSelected = false;
							testPO = nullptr;
							activePlayer = game::Ownership::Player1;
							ActivePlayerText.setString("Player 1");
						}
						std::cout << (int)activePlayer;
					}

					if (m_event.key.code == sf::Keyboard::Num1)
					{
						if (unitIsSelected) {
							if (testPO->getIsBuilding() == true && testPO->getOwner() == activePlayer)
							{
								testPO->build(testPO->getLocation(), &testOM);
							}
						}
					}
					break;

					
			default:
				break;
			}
		}
	}

	void Game::update()
	{																	//View movement map
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

		auto mouse_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*m_window));
		m_cursor.setPosition(mouse_position);
	}

	void Game::render()
	{
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
		m_window->draw(ActivePlayerText);
		m_window->draw(m_gui.GetPlayerStateText());
		m_window->draw(m_gui.text);
		m_window->draw(m_cursor);

		m_window->setView(m_view);
		m_window->draw(selectedMapTile);
		m_window->display();
	}
}