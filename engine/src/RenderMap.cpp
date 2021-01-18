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
		int tileSize = 100;
		handler.LoadTextures();
		for (int i = 0; i < map.mapsize; i++)
		{
			for (int j = 0; j < map.mapsize; j++)
			{
				
				if ((i + j) % 3)
				{
					texture = handler.getTexture("3.jpg");
					map.tile[i][j].sprite.setTexture(*texture);
					map.tile[i][j].sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
					
				}
				else
				{
					texture = handler.getTexture("4.jpg");
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