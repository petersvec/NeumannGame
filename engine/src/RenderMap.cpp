#include "../include/Map.hpp"
#include "../include/RenderMap.hpp"
#include "../include/TextureHandler.hpp"

namespace engine
{
	RenderMap::RenderMap()
	{

	}

	void RenderMap::InitMapTextures(Map map)
	{
		TextureHandler handler;
		handler.LoadTextures();
		//tu by mala ist vygenerovana mapa
		for (int i = 0; i < map.getHeight(); i++)
		{
			for (int j = 0; j < map.getWidth(); j++)
			{
				if ((i + j) % 3)
				{					
					map.getTile(i, j).get()->getSprite().setTexture(*handler.getTexture("maptexture3"));
					map.getTile(i, j).get()->getSprite().setTextureRect(sf::IntRect(0, 0, 100, 100));
				}
				else
				{
					
					map.getTile(i, j).get()->getSprite().setTexture(*handler.getTexture("maptexture4"));
					map.getTile(i, j).get()->getSprite().setTextureRect(sf::IntRect(0, 0, 100, 100));
				}
			}
		}
	}

	void RenderMap::RenderM(Map map, sf::RenderTexture& rTex) 
	{
		for (int i = 0; i < map.getHeight(); i++)
		{
			for (int j = 0; j < map.getWidth(); j++)
			{
				rTex.draw(map.getTile(i, j).get()->getSprite());
			}
		}
	}
}