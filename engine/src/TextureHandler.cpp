#include "../include/TextureHandler.hpp"
#include <fstream>
#include <iostream>

namespace engine
{
    TextureHandler::TextureHandler() {}

    void TextureHandler::LoadTextures()
    {
        for (auto &[key, value] : config->getTextures())
        {
            sf::Texture* tex = new sf::Texture();
            tex->loadFromFile(value);
            textureMap[key] = tex;
        }
    }

    sf::Texture* TextureHandler::getTexture(const std::string& name)
    {
        if (textureMap.find(name) == textureMap.end())
        {
            return nullptr;
        }
        else
        {
            return textureMap[name];
        }
    }
}