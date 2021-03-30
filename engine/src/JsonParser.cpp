#include "../include/JsonParser.hpp"

namespace engine
{
    bool JsonParser::setGameConfig(const char* jsonFile, const char* jsonType)
    {
        using namespace rapidjson;
        setConfigType(jsonType);

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
            !m_gameConfigFile.IsObject())
        {
            m_gameConfigFile = nullptr;
            return false;
        }

        return true;
    }

    void JsonParser::setConfigType(const char* jsonType)
    {
        m_configType = std::string(jsonType);
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

    std::unique_ptr<std::vector<std::string>> JsonParser::getTextures()
    {
        std::unique_ptr<std::vector<std::string>> textures = std::make_unique<std::vector<std::string>>();
        if (!m_gameConfigFile.HasMember("Textures") ||
            !m_gameConfigFile["Textures"].IsObject() ||
            !m_gameConfigFile["Textures"].HasMember("Jupiter") ||
            !m_gameConfigFile["Textures"].HasMember("Mars") ||
            !m_gameConfigFile["Textures"].HasMember("Mercury") ||
            !m_gameConfigFile["Textures"].HasMember("Void") ||
            !m_gameConfigFile["Textures"].HasMember("AirBase") ||
            !m_gameConfigFile["Textures"].HasMember("Melee") ||
            !m_gameConfigFile["Textures"].HasMember("MilitaryBase") ||
            !m_gameConfigFile["Textures"].HasMember("Mine") ||
            !m_gameConfigFile["Textures"].HasMember("Probe") ||
            !m_gameConfigFile["Textures"].HasMember("Ranged") ||
            !m_gameConfigFile["Textures"].HasMember("SpaceStation") ||
            !m_gameConfigFile["Textures"].HasMember("Tower") ||
            !m_gameConfigFile["Textures"].HasMember("Worker"))
        {
            const rapidjson::Value& texture = m_gameConfigFile["Textures"];
            
            if (!texture["Jupiter"].IsArray() ||
                !texture["Mars"].IsArray() ||
                !texture["Mercury"].IsArray() ||
                !texture["Void"].IsArray() ||
                !texture["AirBase"].IsArray() ||
                !texture["Melee"].IsArray() ||
                !texture["MilitaryBase"].IsArray() ||
                !texture["Mine"].IsArray() ||
                !texture["Probe"].IsArray() ||
                !texture["Ranged"].IsArray() ||
                !texture["SpaceStation"].IsArray() ||
                !texture["Tower"].IsArray() ||
                !texture["Worker"].IsArray())
            {
                return nullptr;
            }

            textures.get()->push_back(texture["Jupiter"].GetString());
            textures.get()->push_back(texture["Mars"].GetString());
            textures.get()->push_back(texture["Mercury"].GetString());
            textures.get()->push_back(texture["Void"].GetString());
            textures.get()->push_back(texture["AirBase"].GetString());
            textures.get()->push_back(texture["Melee"].GetString());
            textures.get()->push_back(texture["MilitaryBase"].GetString());
            textures.get()->push_back(texture["Mine"].GetString());
            textures.get()->push_back(texture["Probe"].GetString());
            textures.get()->push_back(texture["Ranged"].GetString());
            textures.get()->push_back(texture["SpaceStation"].GetString());
            textures.get()->push_back(texture["Tower"].GetString());
            textures.get()->push_back(texture["Worker"].GetString());

            return textures;
        }
        else
        {
            return nullptr;
        }
    }
}