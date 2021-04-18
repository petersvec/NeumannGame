#include "../include/RenderMap.hpp"

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

		for (int i = 0; i < map.getHeight(); i++)
		{
			for (int j = 0; j < map.getWidth(); j++)
			{
				switch (map.getTile(i, j)->getType())
				{
				case 0:
					map.getTile(i, j)->setSprite(*textures->getTexture("Void"));
					break;
				case 1:
					map.getTile(i, j)->setSprite(*textures->getTexture("Jupiter"));
					break;
				case 2:
					map.getTile(i, j)->setSprite(*textures->getTexture("Mercury"));
					break;
				case 3:
					map.getTile(i, j)->setSprite(*textures->getTexture("Mars"));
					break;
				default:
					map.getTile(i, j)->setSprite(*textures->getTexture("Void"));
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