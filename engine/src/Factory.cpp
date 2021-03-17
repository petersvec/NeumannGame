#include "../include/Factory.hpp"

namespace engine
{
    Factory::Factory(){}

    IObject Factory::getObject(game::ObjectType objType)
    {
        switch (objType)
        {
        case game::ObjectType::Meele:
            return new game::Meele();
        case game::ObjectType::Probe:
            return new game::Probe();
        case game::ObjectType::Ranged:
            return new game::Ranged();
        case game::ObjectType::Worker:
            return new game::Worker();
        case game::ObjectType::AirBase:
            return new game::AirBase();
        case game::ObjectType::MilitaryBase:
            return new game::MilitaryBase();
        case game::ObjectType::Mine:
            return new game::Mine();
        case game::ObjectType::SpaceStation:
            return new game::SpaceStation();
        case game::ObjectType::Tower:
            return new game::Tower();
        default:
            throw "Invalid object!";
        }
    }
}