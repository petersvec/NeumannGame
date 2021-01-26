#include "../include/Map.hpp"
#include "../include/RenderMap.hpp"
#include "../include/TextureHandler.hpp"

namespace engine
{
	RenderMap::RenderMap()
	{

	}

	void RenderMap::initMapTextures(Map map)
	{
		TextureHandler handler;
		handler.LoadTextures();
		for (int i = 0; i < map.getHeight(); i++)
		{
			for (int j = 0; j < map.getWidth(); j++)
			{
				if (map.getTile(i, j).get()->getType() == 0)
				{					
					map.getTile(i, j).get()->getSprite().setTexture(*handler.getTexture("Void"));
					map.getTile(i, j).get()->getSprite().setTextureRect(sf::IntRect(0, 0, 100, 100));
				}
				else if (map.getTile(i, j).get()->getType() == 1)
				{
					map.getTile(i, j).get()->getSprite().setTexture(*handler.getTexture("Jupiter"));
					map.getTile(i, j).get()->getSprite().setTextureRect(sf::IntRect(0, 0, 100, 100));
				}
				else if (map.getTile(i, j).get()->getType() == 2)
				{
					map.getTile(i, j).get()->getSprite().setTexture(*handler.getTexture("Mercury"));
					map.getTile(i, j).get()->getSprite().setTextureRect(sf::IntRect(0, 0, 100, 100));
				}
				else
				{
					map.getTile(i, j).get()->getSprite().setTexture(*handler.getTexture("Mars"));
					map.getTile(i, j).get()->getSprite().setTextureRect(sf::IntRect(0, 0, 100, 100));
				}
			}
		}
	}

	void RenderMap::renderMap(Map map, sf::RenderTexture& renderTexture) 
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