#include "../include/Factory.hpp"

namespace engine
{
    Factory::Factory(){}

    IObjectPtr Factory::getObject(game::ObjectType objType)
    {
        switch (objType)
        {
        case game::ObjectType::Melee:
            return std::make_shared<game::Melee>(game::Melee(objType, /*texture*/, 1, 5, 5));
        case game::ObjectType::Probe:
            return std::make_shared<game::Probe>(game::Probe(objType, /*texture*/, 1, 5, 5));
        case game::ObjectType::Ranged:
            return std::make_shared<game::Ranged>(game::Ranged(objType, /*texture*/, 1, 5, 5));
        case game::ObjectType::Worker:
            return std::make_shared<game::Worker>(game::Worker(objType, /*texture*/, 1, 5, 5));
        case game::ObjectType::AirBase:
            return std::make_shared<game::AirBase>(game::AirBase(objType, /*texture*/, 1000, 1000, 1000));
        case game::ObjectType::MilitaryBase:
            return std::make_shared<game::MilitaryBase>(game::MilitaryBase(objType, /*texture*/, 500, 500, 500));
        case game::ObjectType::Mine:
            return std::make_shared<game::Mine>(game::Mine(objType, /*texture*/, 100, 100, 100));
        case game::ObjectType::SpaceStation:
            return std::make_shared<game::SpaceStation>(game::SpaceStation(objType, /*texture*/, 5000, 5000, 5000));
        case game::ObjectType::Tower:
            return std::make_shared<game::Tower>(game::Tower(objType, /*texture*/, 0, 10, 10, 1000, 1000, 1000));
        default:
            throw "Invalid object!";
        }
    }
}