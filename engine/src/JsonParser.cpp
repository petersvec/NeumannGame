#include "../include/JsonParser.hpp"
#include "../include/Map.hpp"

namespace engine
{
    bool JsonParser::setGameConfig(const char* jsonFile, const char* jsonType)
    {
        using namespace rapidjson;

        FILE* fp = nullptr;
        fopen_s(&fp, jsonFile, "rb");

        if (!fp)
        {
            m_gameConfigFile = nullptr;
            return false;
        }

        char readBuffer[1024] = "";
        FileReadStream is(fp, readBuffer, sizeof(readBuffer));

        m_gameConfigFile.ParseStream(is);

        fclose(fp);

        if (m_gameConfigFile.HasParseError() ||
            !m_gameConfigFile.IsObject() ||
            !m_gameConfigFile.HasMember(jsonType))
        {
            m_gameConfigFile = nullptr;
            return false;
        }

        return true;
    }

    unsigned short JsonParser::getMapHeight()
    {
        unsigned short mapHeight;
        if (m_gameConfigFile.HasMember("MapHeight"))
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
        else if (mapHeight < G_MIN_MAP_SIZE)
        {
            return G_MIN_MAP_SIZE;
        }
        else
        {
            return mapHeight;
        }
    }

    unsigned short JsonParser::getMapWidth()
    {
        unsigned short mapWidth;
        if (m_gameConfigFile.HasMember("MapWidth"))
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
        else if (mapWidth < G_MIN_MAP_SIZE)
        {
            return G_MIN_MAP_SIZE;
        }
        else
        {
            return mapWidth;
        }
    }

    unsigned short JsonParser::getNumberOfPlanets()
    {
        unsigned short numberOfPlanets;
        if (m_gameConfigFile.HasMember("NumberOfPlanets"))
        {
            numberOfPlanets = m_gameConfigFile["NumberOfPlanets"].GetInt();
        }
        else
        {
            numberOfPlanets = G_MIN_NUMBER_OF_PLANETS;
        }

        if (numberOfPlanets < G_MIN_NUMBER_OF_PLANETS)
        {
            return G_MIN_NUMBER_OF_PLANETS;
        }
        else
        {
            return numberOfPlanets;
        }
    }

    unsigned char JsonParser::getMaxRadiusOfPlanet()
    {
        unsigned char maxRadiusOfPlanet;
        if (m_gameConfigFile.HasMember("MaxRadiusOfPlanet"))
        {
            maxRadiusOfPlanet = m_gameConfigFile["MaxRadiusOfPlanet"].GetInt();
        }
        else
        {
            maxRadiusOfPlanet = G_MIN_RADIUS_OF_PLANET;
        }

        if (maxRadiusOfPlanet < G_MIN_RADIUS_OF_PLANET)
        {
            return G_MIN_RADIUS_OF_PLANET;
        }
        else
        {
            return maxRadiusOfPlanet;
        }
    }
}