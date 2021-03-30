#include "../include/TextureHandler.hpp"
#include <fstream>
#include <iostream>

namespace engine
{
    TextureHandler::TextureHandler() {}

    void TextureHandler::LoadTextures()
    {
        textureMap.begin();
        std::ifstream file("textureslist.txt");
        std::string line;
        int i=0, numberOfLines=0;
        std::string delimiter = "::";
        std::string texturePath;
        int pos = 0;
        
        while (std::getline(file, line))
        {
            numberOfLines++;
        }
        file.clear();
        file.seekg(0);
        
        retText = new sf::Texture();
        text = new sf::Texture * [numberOfLines];

        for (i = 0; i < numberOfLines; i++)
        {
            text[i] = new sf::Texture();
        }
        i = 0;

        while (std::getline(file, line))
        {
            pos = line.find(delimiter);
            texturePath = line.substr(0, pos);
            line = line.erase(0, pos + 2);
            text[i]->loadFromFile(texturePath);
            textureMap.insert(std::pair < std::string, sf::Texture* >(line, text[i]));
            i++;
        }
    }

    sf::Texture* TextureHandler::getTexture(std::string str)
    {
        retText = textureMap.at(str);
        return retText;
    }
}