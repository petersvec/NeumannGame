#include "../include/Factory.hpp"

namespace engine
{
    Factory::Factory(){}

    IObjectPtr Factory::getObject(game::ObjectType objType, sf::Texture texture, TilePtr location)
    {
        switch (objType)
        {
        case game::ObjectType::Melee:
            return std::make_shared<game::Melee>(game::Melee(objType, texture, location, 1, 5, 5));
        case game::ObjectType::Probe:
            return std::make_shared<game::Probe>(game::Probe(objType, texture, location, 15, 5, 5));
        case game::ObjectType::Ranged:
            return std::make_shared<game::Ranged>(game::Ranged(objType, texture, location, 3, 5, 2));
        case game::ObjectType::Worker:
            return std::make_shared<game::Worker>(game::Worker(objType, texture, location, 5, 1, 1));
        case game::ObjectType::AirBase:
            return std::make_shared<game::AirBase>(game::AirBase(objType, texture, location, 1000, 1000, 1000));
        case game::ObjectType::MilitaryBase:
            return std::make_shared<game::MilitaryBase>(game::MilitaryBase(objType, texture, location, 500, 500, 500));
        case game::ObjectType::Mine:
            return std::make_shared<game::Mine>(game::Mine(objType, texture, location, 100, 100, 100));
        case game::ObjectType::SpaceStation:
            return std::make_shared<game::SpaceStation>(game::SpaceStation(objType, texture, location, 5000, 5000, 5000));
        case game::ObjectType::Tower:
            return std::make_shared<game::Tower>(game::Tower(objType, texture, location, 15, 10, 10, 1000, 1000, 1000));
        default:
            throw "Invalid object!";
        }
    }
}