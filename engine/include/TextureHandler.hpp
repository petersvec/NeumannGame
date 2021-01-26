#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <map>
#include "../include/Game.hpp"

namespace engine
{
	class TextureHandler
	{
	public:
		TextureHandler();
		void LoadTextures();
		sf::Texture* getTexture(std::string str);
	private:
		std::map<std::string, sf::Texture*> texturemap;
		sf::Texture** text;
		sf::Texture* retText;

		
		
		
		
	};

}