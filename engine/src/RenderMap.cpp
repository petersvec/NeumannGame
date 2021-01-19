#include "RenderMap.hpp"
#include <TextureHandler.hpp>
#include <Map.hpp>

namespace engine
{
	RenderMap::RenderMap()
	{

	}

	void RenderMap::InitMapTextures(Map& map)
	{
		sf::Texture *texture = new sf::Texture();
		TextureHandler handler;
		handler.LoadTextures();

		for (int i = 0; i < map.mapsize; i++)
		{
			for (int j = 0; j < map.mapsize; j++)
			{
				if ((i + j) % 3)
				{
					texture = handler.getTexture("maptexture3");
					map.tile[i][j].sprite.setTexture(*texture);
					map.tile[i][j].sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
				}
				else
				{
					texture = handler.getTexture("maptexture4");
					map.tile[i][j].sprite.setTexture(*texture);
					map.tile[i][j].sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));	
				}
			}
		}
	}

	void RenderMap::RenderM(Map &map, sf::RenderTexture &rTex) 
	{
		for (int i = 0; i < map.mapsize; i++)
		{
			for (int j = 0; j < map.mapsize; j++)
			{
				rTex.draw(map.tile[i][j].sprite);
			}
		}
	}
}