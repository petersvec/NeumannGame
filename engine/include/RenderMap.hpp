#pragma once
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "Map.hpp"
#include "JsonParser.hpp"
#include "TextureHandler.hpp"

namespace engine
{
	class RenderMap
	{
	private:
		
	public:
		sf::Shader shader;

	public:
		RenderMap();
		void initMapTextures(Map&);
		void renderMap(Map&, sf::RenderTexture&);
	};
}