#pragma once
#include <SFML/Graphics.hpp>
#include "../include/MapGenerator.hpp"
#include "../include/Map.hpp"
#include "..\include\RenderMap.hpp"

namespace engine
{
	class Game
	{
	private:
		//Private variables
		//Window
		
		sf::VideoMode videoMode;
		sf::Event event;
		MapGenerator mapGen;
		Map map;
		sf::View view1;
		sf::RenderTexture rTex;
		sf::Sprite sprite;
		float ZoomLevel = 1;
		int tileSize = 50;
		sf::Vector2i pixelPos;


		sf::Vector2f worldPos;

		sf::Texture* text3;
		const sf::Texture texture;
		RenderMap RenderMap;

		//Private functions
		void initVariables();
		void initWindow();
		void initTiles();
		void initTile(size_t i, size_t j);
		Tile getTile(int x, int y);


	public:
		sf::RenderWindow* window;
		//Constructors & destructor
		Game();
		virtual ~Game();

		//Accessors
		const bool isRunning() const;

		//Public functions
		void pollEvents();
		void update();
		void render();
	};
}