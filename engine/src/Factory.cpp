#include "../include/Factory.hpp"

namespace engine
{
    IObjectPtr Factory::getObject(game::ObjectType objType, TilePtr location, TextureHandler textureHandler)
    {
        sf::Texture texture;
        switch (objType)
        {
        case game::ObjectType::Melee:
            texture = *textureHandler.getTexture("Melee");
            return std::make_shared<game::Melee>(game::Melee(100, objType, texture, location, 1, 5, 5));
        case game::ObjectType::Probe:
            texture = *textureHandler.getTexture("Probe");
            return std::make_shared<game::Probe>(game::Probe(1000, objType, texture, location, 15, 5, 5));
        case game::ObjectType::Ranged:
            texture = *textureHandler.getTexture("Ranged");
            return std::make_shared<game::Ranged>(game::Ranged(50, objType, texture, location, 3, 5, 2));
        case game::ObjectType::Worker:
            texture = *textureHandler.getTexture("Worker");
            return std::make_shared<game::Worker>(game::Worker(25, objType, texture, location, 5, 1, 1));
        case game::ObjectType::AirBase:
            texture = *textureHandler.getTexture("AirBase");
            return std::make_shared<game::AirBase>(game::AirBase(2500, objType, texture, location, 1000, 1000, 1000));
        case game::ObjectType::MilitaryBase:
            texture = *textureHandler.getTexture("MilitaryBase");
            return std::make_shared<game::MilitaryBase>(game::MilitaryBase(2500, objType, texture, location, 500, 500, 500));
        case game::ObjectType::Mine:
            texture = *textureHandler.getTexture("Mine");
            return std::make_shared<game::Mine>(game::Mine(500, objType, texture, location, 100, 100, 100));
        case game::ObjectType::SpaceStation:
            texture = *textureHandler.getTexture("SpaceStation");
            return std::make_shared<game::SpaceStation>(game::SpaceStation(10000, objType, texture, location, 5000, 5000, 5000));
        case game::ObjectType::Tower:
            texture = *textureHandler.getTexture("Tower");
            return std::make_shared<game::Tower>(game::Tower(2000, objType, texture, location, 15, 10, 10, 1000, 1000, 1000));
        default:
            throw "Invalid object!";
        }
    }
}