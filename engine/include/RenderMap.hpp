#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include "Map.hpp"

namespace engine
{
	class RenderMap
	{
	private:

	public:
		RenderMap();
		void initMapTextures(Map& map);
		void renderMap(Map& map, sf::RenderTexture& renderTexture);
	};
}