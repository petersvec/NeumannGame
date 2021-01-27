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

				switch (tile.getType())
				{
				case 0:
					tile.setSprite(*handler.getTexture("Void"));
					break;
				case 1:
					tile.setSprite(*handler.getTexture("Jupiter"));
					break;
				case 2:
					tile.setSprite(*handler.getTexture("Mercury"));
					break;
				case 3:
					tile.setSprite(*handler.getTexture("Mars"));
					break;
				default:
					tile.setSprite(*handler.getTexture("Void"));
					break;
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