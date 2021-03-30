#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <map>
#include "../include/Game.hpp"

namespace engine
{
	class TextureHandler
	{
	private:
		std::map<std::string, sf::Texture*> textureMap;
		sf::Texture** text;
		sf::Texture* retText;

	public:
		TextureHandler();
		void LoadTextures();
		sf::Texture* getTexture(std::string);
	};

}