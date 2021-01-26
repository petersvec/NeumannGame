#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include "Map.hpp"

namespace engine
{
	class RenderMap {
	public:
		RenderMap();
		void InitMapTextures(Map& map);
		void RenderM(Map &map, sf::RenderTexture& rTex);
	private:
	};
}