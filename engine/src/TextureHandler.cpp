#include "../include/TextureHandler.hpp"
#include <fstream>
#include <iostream>

namespace engine
{
    TextureHandler::TextureHandler() {}

    void TextureHandler::LoadTextures()
    {
        texturemap.begin();
        std::ifstream file("textureslist.txt");
        std::string line;
        int i=0, numberofLines=0;
        std::string delimiter = "::";
        std::string texturepath;
        int pos = 0;
        
        while (std::getline(file, line))
        {
            numberofLines++;
        }
        file.clear();
        file.seekg(0);
        
        retText = new sf::Texture();
        text = new sf::Texture * [numberofLines];

        for (i = 0; i < numberofLines; i++)
        {
            text[i] = new sf::Texture();
        }
        i = 0;

        while (std::getline(file, line))
        {
            pos = line.find(delimiter);
            texturepath = line.substr(0, pos);
            line = line.erase(0, pos + 2);
            text[i]->loadFromFile(texturepath);
            texturemap.insert(std::pair < std::string, sf::Texture* >(line, text[i]));
            i++;
        }
    }

    sf::Texture* TextureHandler::getTexture(std::string str)
    {
        retText = texturemap.at(str);
        return retText;
    }

}