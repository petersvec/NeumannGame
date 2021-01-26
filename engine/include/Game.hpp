#pragma once
#include <SFML/Graphics.hpp>
#include "MapGenerator.hpp"
#include "RenderMap.hpp"

namespace engine
{
	class Game
	{
	private:
		sf::RenderWindow* m_window;
		sf::Event m_event;
		Map m_gameMap;
		MapGenerator m_mapGenerator;

		sf::VideoMode videoMode;
		sf::View view1;
		sf::RenderTexture rTex;
		sf::Sprite sprite;
		float ZoomLevel = 1;
		int tileSize = 50;
		sf::Vector2i pixelPos;

		sf::Vector2f worldPos;

		sf::Texture* text3;
		const sf::Texture texture;
		sf::RectangleShape tile;
		RenderMap RenderMap;

		void initVariables();
		void initWindow();
		void initTiles();
		void initTile(size_t i, size_t j);
		Tile getTile(int x, int y);

	public:
		Game();
		virtual ~Game();

		const bool isRunning() const;
		void pollEvents();
		void update();
		void render();
	};
}