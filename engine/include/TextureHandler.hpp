#pragma once
#include <map>
#include <string>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include "JsonParser.hpp"

namespace engine
{
	class TextureHandler;
	extern std::unique_ptr<TextureHandler> textures;

	class TextureHandler
	{
	private:
		std::map<std::string, sf::Texture*> textureMap;

	public:
		TextureHandler();
		void LoadTextures();
		sf::Texture* getTexture(const std::string&);
	};

}