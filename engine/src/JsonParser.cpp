#include "../include/JsonParser.hpp"
#include "../include/Map.hpp"

namespace engine
{
    bool JsonParser::setGameConfig(const char* jsonFile, const char* jsonType)
    {
        using namespace rapidjson;

        std::ifstream ifs{ (jsonFile) };

        if (!ifs.is_open())
        {
            m_gameConfigFile = nullptr;
            return false;
        }

        IStreamWrapper isw{ ifs };

        m_gameConfigFile->ParseStream(isw);

        if (!m_gameConfigFile->HasParseError() ||
            !m_gameConfigFile->IsObject() ||
            !m_gameConfigFile->HasMember(jsonType))
        {
            m_gameConfigFile = nullptr;
            return false;
        }

        return true;
    }

    unsigned short JsonParser::getMapHeight()
    {
        unsigned short mapHeight;
        if (m_gameConfigFile->HasMember("MapHeight"))
        {
            mapHeight = m_gameConfigFile["MapHeight"].GetInt();
        }
        else
        {
            mapHeight = G_MIN_MAP_SIZE;
        }

        if (mapHeight > G_MAX_MAP_SIZE)
        {
            return G_MAX_MAP_SIZE;
        }
        else
        {
            return mapHeight;
        }
    }

    unsigned short JsonParser::getMapWidth()
    {
        unsigned short mapWidth;
        if (m_gameConfigFile->HasMember("MapHeight"))
        {
            mapWidth = m_gameConfigFile["MapWidth"].GetInt();
        } 
        else
        {
            mapWidth = G_MIN_MAP_SIZE;
        }

        if (mapWidth > G_MAX_MAP_SIZE)
        {
            return G_MAX_MAP_SIZE;
        }
        else
        {
            return mapWidth;
        }
    }

    unsigned short JsonParser::getNumberOfPlanets()
    {
        unsigned short numberOfPlanets = m_gameConfigFile["NumberOfPlanets"].GetInt();
        return numberOfPlanets;
    }

    unsigned char JsonParser::getMaxRadiusOfPlanet()
    {
        unsigned char maxRadiusOfPlanet = m_gameConfigFile["MaxRadiusOfPlanet"].GetInt();
        return maxRadiusOfPlanet;
    }
}