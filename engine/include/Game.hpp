#pragma once
#include <SFML/Graphics.hpp>
#include "MapGenerator.hpp"
#include "RenderMap.hpp"
#include <TextureHandler.hpp>

namespace engine
{
	class Game
	{
	private:
		sf::RenderWindow* m_window;
		sf::Event m_event;
		Map* m_gameMap;
		MapGenerator m_mapGenerator;
		sf::Sprite m_frame;
		sf::VideoMode m_videoMode;
		sf::View m_view;
		sf::RenderTexture m_renderTexture;
		float ZoomLevel = 1;
		int tileSize = 50;
		sf::Vector2i pixelPos;
		sf::Vector2f worldPos;
		const sf::Texture texture;
		RenderMap m_renderMap;

		void initVariables();
		void initWindow();

	public:
		Game();
		virtual ~Game();

		void clickMap(int x, int y);
		void displayText(sf::String str);
		const bool isRunning() const;
		void pollEvents();
		void update();
		void render();
	};
}