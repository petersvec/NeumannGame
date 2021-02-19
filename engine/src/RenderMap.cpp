#include "../include/RenderMap.hpp"
#include "../include/TextureHandler.hpp"

namespace engine
{
	RenderMap::RenderMap()
	{

	}

	void RenderMap::initMapTextures(Map& map)
	{
		

		if (!shader.loadFromFile("storm.vert", sf::Shader::Vertex))
		{
			// error...
		}
		//if (!shader.loadFromFile("blink.frag", sf::Shader::Fragment))
		//{

		//}

		TextureHandler* handler = new TextureHandler();
		handler->LoadTextures();
		for (int i = 0; i < map.getHeight(); i++)
		{
			for (int j = 0; j < map.getWidth(); j++)
			{
				switch (map.getTile(i, j)->getType())
				{
				case 0:
					map.getTile(i, j)->setSprite(*(handler)->getTexture("Void"));
					break;
				case 1:
					map.getTile(i, j)->setSprite(*(handler)->getTexture("Jupiter"));
					break;
				case 2:
					map.getTile(i, j)->setSprite(*(handler)->getTexture("Mercury"));
					break;
				case 3:
					map.getTile(i, j)->setSprite(*(handler)->getTexture("Mars"));
					break;
				default:
					map.getTile(i, j)->setSprite(*(handler)->getTexture("Void"));
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
				renderTexture.draw(map.getTile(i, j).get()->getSprite(), &shader);
			}
		}
	}
}