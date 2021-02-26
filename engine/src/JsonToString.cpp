#include "../include/JsonToString.hpp"

namespace engine
{
    JsonToString::JsonToString()
    {
        if ((toString()) != EXIT_FAILURE)
        {
            return;
        }
    }

    JsonToString::~JsonToString()
    {

    }

    int JsonToString::toString()
    {
        using namespace rapidjson;

        std::ifstream ifs{ R"(../../config.json)" };

        if (!ifs.is_open())
        {
            m_configFile = nullptr;
            return EXIT_FAILURE;
        }

        IStreamWrapper isw{ ifs };

        m_configFile->ParseStream(isw);

        StringBuffer buffer{};
        Writer<StringBuffer> writer{ buffer };
        m_configFile->Accept(writer);

        if (m_configFile->HasParseError())
        {
            std::cout << "Error  : " << m_configFile->GetParseError() << '\n'
                      << "Offset : " << m_configFile->GetErrorOffset() << '\n';
            m_configFile = nullptr;
            return EXIT_FAILURE;
        }

        const std::string jsonStr{ buffer.GetString() };

        std::cout << jsonStr << '\n';

        return EXIT_SUCCESS;
    }
}