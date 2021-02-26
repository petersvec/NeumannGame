#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Shader.hpp>
#include "Map.hpp"

namespace engine
{
	class RenderMap
	{
	private:
		
	public:
		sf::Shader shader;

	public:
		RenderMap();
		void initMapTextures(Map& map);
		void renderMap(Map& map, sf::RenderTexture& renderTexture);
	};
}