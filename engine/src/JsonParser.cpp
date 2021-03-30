#include "../include/JsonParser.hpp"

namespace engine
{
    std::unique_ptr<JsonParser> config = std::make_unique<JsonParser>();

    bool JsonParser::setGameConfig(const std::string &jsonFile, const std::string &jsonType)
    {
        using namespace rapidjson;
        setConfigType(jsonType);

        FILE* fp = nullptr;
        fopen_s(&fp, jsonFile.c_str(), "rb");

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
            !m_gameConfigFile.IsObject())
        {
            m_gameConfigFile = nullptr;
            return false;
        }

        return true;
    }

    void JsonParser::setConfigType(const std::string &jsonType)
    {
        m_configType = jsonType;
    }

    unsigned short JsonParser::getMapHeight()
    {
        int mapHeight = G_MIN_MAP_SIZE;
        if (!m_gameConfigFile.HasMember("MapHeight") ||
            !m_gameConfigFile["MapHeight"].IsNumber() ||
            !m_gameConfigFile["MapHeight"].IsInt() ||
            ((mapHeight = m_gameConfigFile["MapHeight"].GetInt()) >= G_MAX_MAP_SIZE))
        {
            return G_MAX_MAP_SIZE;
        }
        else if (mapHeight > G_MIN_MAP_SIZE)
        {
            return mapHeight;
        }
        else
        {
            return G_MIN_MAP_SIZE;
        }
    }

    unsigned JsonParser::getTileSize() const
    {
        if (m_gameConfigFile.HasMember("TileSize") && m_gameConfigFile["TileSize"].IsInt())
        {
            return m_gameConfigFile["TileSize"].GetInt();
        }
        else
        {
            return G_MIN_TILE_SIZE;
        }
    }

    unsigned short JsonParser::getMapWidth()
    {
        int mapWidth = G_MIN_MAP_SIZE;
        if (!m_gameConfigFile.HasMember("MapWidth") ||
            !m_gameConfigFile["MapWidth"].IsNumber() ||
            !m_gameConfigFile["MapWidth"].IsInt() ||
            ((mapWidth = m_gameConfigFile["MapWidth"].GetInt()) >= G_MAX_MAP_SIZE))
        {
            return G_MAX_MAP_SIZE;
        }
        else if (mapWidth > G_MIN_MAP_SIZE)
        {
            return mapWidth;
        }
        else
        {
            return G_MIN_MAP_SIZE;
        }
    }

    unsigned short JsonParser::getNumberOfPlanets()
    {
        int numberOfPlanets = G_MIN_NUMBER_OF_PLANETS;
        if (!m_gameConfigFile.HasMember("NumberOfPlanets") ||
            !m_gameConfigFile["NumberOfPlanets"].IsNumber() ||
            !m_gameConfigFile["NumberOfPlanets"].IsInt() ||
            ((numberOfPlanets = m_gameConfigFile["NumberOfPlanets"].GetInt()) < G_MIN_NUMBER_OF_PLANETS))
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
        int maxRadiusOfPlanet = G_MIN_RADIUS_OF_PLANET;
        if (!m_gameConfigFile.HasMember("MaxRadiusOfPlanet") ||
            !m_gameConfigFile["MaxRadiusOfPlanet"].IsNumber() ||
            !m_gameConfigFile["MaxRadiusOfPlanet"].IsInt() ||
            ((maxRadiusOfPlanet = m_gameConfigFile["MaxRadiusOfPlanet"].GetInt()) < G_MIN_RADIUS_OF_PLANET))
        {
            return G_MIN_RADIUS_OF_PLANET;
        }
        else
        {
            return maxRadiusOfPlanet;
        }
    }

    std::map<std::string, std::string> JsonParser::getTextures()
    {
        std::map<std::string, std::string> texturePairs;

        if (m_gameConfigFile.HasMember("Textures"))
        {
            const rapidjson::Value& textures = m_gameConfigFile["Textures"].GetObject();

            for (auto& m : textures.GetObject()) {
                texturePairs[m.name.GetString()] = m.value.GetString();
            }
        }
        return texturePairs;
    }
}