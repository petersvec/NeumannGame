#include "../include/RenderMap.hpp"
#include "../../game/include/Tile.hpp"
#include <SFML/Graphics/VertexArray.hpp>

namespace engine
{
	RenderMap::RenderMap()
	{
		loadShaders();
	}

	void RenderMap::setupShader(const sf::Texture& texture)
	{
		m_pixel_shader.setUniform("texture", texture);
	}

	void RenderMap::loadShaders()
	{
		m_pixel_shader.loadFromFile("data\\shaders\\post_process.frag", sf::Shader::Fragment);
	}

	void RenderMap::initMapTextures(Map& map)
	{
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
				renderTexture.draw(map.getTile(i, j).get()->getSprite());
			}
		}
	}
}