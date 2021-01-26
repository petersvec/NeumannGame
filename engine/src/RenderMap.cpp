#include "../include/Map.hpp"
#include "../include/RenderMap.hpp"
#include "../include/TextureHandler.hpp"

namespace engine
{
	RenderMap::RenderMap()
	{

	}

	void RenderMap::initMapTextures(Map& map)
	{
		TextureHandler handler;
		handler.LoadTextures();
		for (int i = 0; i < map.getHeight(); i++)
		{
			for (int j = 0; j < map.getWidth(); j++)
			{
				Tile tile = *map.getTile(i, j).get();
				if (tile.getType() == 0)
				{					
					tile.getSprite().setTexture(*handler.getTexture("Void"));
					tile.getSprite().setTextureRect(sf::IntRect(0, 0, 100, 100));
				}
				else if (tile.getType() == 1)
				{
					tile.getSprite().setTexture(*handler.getTexture("Jupiter"));
					tile.getSprite().setTextureRect(sf::IntRect(0, 0, 100, 100));
				}
				else if (tile.getType() == 2)
				{
					tile.getSprite().setTexture(*handler.getTexture("Mercury"));
					tile.getSprite().setTextureRect(sf::IntRect(0, 0, 100, 100));
				}
				else
				{
					tile.getSprite().setTexture(*handler.getTexture("Mars"));
					tile.getSprite().setTextureRect(sf::IntRect(0, 0, 100, 100));
				}
			}
		}
	}

	void RenderMap::renderMap(Map& map, sf::RenderTexture& renderTexture) 
	{
		for (int i = 0; i < map.getHeight(); i++)
		{
			for (int j = 0; j < map.getWidth(); j++)
			{
				renderTexture.draw(map.getTile(i, j).get()->getSprite());
			}
		}
	}
}