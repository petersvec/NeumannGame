#include "../include/JsonParser.hpp"

namespace engine
{
    void JsonParser::setGameConfig(const char* jsonFile)
    {
        m_gameConfigFile.Parse(jsonFile);
    }
    
    unsigned short JsonParser::getMaxMapSize()
    {
        return m_gameConfigFile["MaxMapSize"].GetInt();
    }

    unsigned short JsonParser::getMapHeight()
    {
        unsigned short mapHeight = m_gameConfigFile["MapHeight"].GetInt();
        if (mapHeight > getMaxMapSize())
            return getMaxMapSize();
        return mapHeight;
    }

    unsigned short JsonParser::getMapWidth()
    {
        unsigned short mapWidth = m_gameConfigFile["MapWidth"].GetInt();
        if (mapWidth > getMaxMapSize())
            return getMaxMapSize();
        return mapWidth;
    }

    unsigned short JsonParser::getNumberOfPlanets()
    {
        
    }

    unsigned char JsonParser::getMaxRadiusOfPlanet()
    {

    }
}