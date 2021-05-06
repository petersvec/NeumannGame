#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Map.hpp"
#include "RenderMap.hpp"
#include "MapGenerator.hpp"
#include "JsonParser.hpp"
#include "ObjectManager.hpp"
#include "IObject.hpp"
#include "Shader.hpp"
#include "TextureHandler.hpp"
#include "UnitFactory.hpp"
#include "../../game/include/player/PlayerState.hpp"
#include "../../game/include/Ownership.hpp"
#include "../../game/include/ObjectType.hpp"

//temporary
#include <iostream>
#include "Gui.hpp"


namespace engine
{
	class Game
	{
	private:
		
		sf::RenderWindow* m_window;
		sf::Event m_event;
		std::shared_ptr<Map> m_gameMap;
		MapGenerator m_mapGenerator;
		sf::Sprite m_frame;
		sf::VideoMode m_videoMode;
		sf::View m_view;
		sf::RenderTexture m_renderTexture;
		float ZoomLevel = 1.f;
		unsigned const char tileSize = 50;
		sf::Vector2i pixelPos;
		sf::Vector2f worldPos;
		const sf::Texture texture;
		RenderMap m_renderMap;
		JsonParser m_gameConfig;
		sf::Text tileText;
		sf::String str;
		sf::View defaultView;
		int changed = 1;
		sf::RectangleShape m_guiRectangle;
		std::shared_ptr<ObjectManager> testOM;
		std::shared_ptr<IObject> testPO;
		bool unitIsSelected;
		sf::RectangleShape selectedMapTile;
		sf::RectangleShape selectedMoveRange;
		game::PlayerState player1State;
		game::PlayerState player2State;
		sf::Text ActivePlayerText;
		Gui m_gui;
		sf::Sprite m_cursor;
		unsigned short tempx, tempy;
	private:
		game::PlayerState& GetCurrentPlayerState();
		game::PlayerState& GetEnemyPlayerState();

	public:
		game::Ownership activePlayer = game::Ownership::Player1;

		void initVariables();
		void initWindow();

	public:
		Game();
		virtual ~Game();

		void endMove();
		void clickMap(int, int);
		void BuildButtonPressed(sf::Event ev, TilePtr tpr);
		void setClickedTile(int, int, sf::RectangleShape*);
		void setDisplayText(sf::Text*, sf::String);
		
		const bool isRunning() const;
		void pollEvents();
		void update();
		void render();
	};
}