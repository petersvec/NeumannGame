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
	public:
		sf::Shader m_pixel_shader;
	private:
		void loadShaders();
	public:
		RenderMap();
		void initMapTextures(Map&);
		void renderMap(Map&, sf::RenderTexture&);

		void  setupShader(const sf::Texture& texture);
	};
}