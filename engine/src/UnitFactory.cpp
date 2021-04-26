#include "../include/UnitFactory.hpp"
#include "../include/IObject.hpp"
#include "../include/TextureHandler.hpp"
#include "../../game/include/buildings/AirBase.hpp"
#include "../../game/include/buildings/MilitaryBase.hpp"
#include "../../game/include/buildings/Mine.hpp"
#include "../../game/include/buildings/SpaceStation.hpp"
#include "../../game/include/buildings/Tower.hpp"
#include "../../game/include/units/Melee.hpp"
#include "../../game/include/units/Probe.hpp"
#include "../../game/include/units/Ranged.hpp"
#include "../../game/include/units/Worker.hpp"
#include "../include/JsonParser.hpp"

namespace engine
{
    UnitFactoryPtr unitFactory = std::make_unique<UnitFactory>();

    std::shared_ptr<IObject> UnitFactory::create(game::ObjectType objType, TilePtr location, game::Ownership owner)
    {
        switch (objType)
        {
        case game::ObjectType::Melee:
            return std::make_shared<game::Melee>(game::Melee(100, objType, *textures->getTexture("Melee"), location, 5, 1, 5, 5, owner));
        case game::ObjectType::Probe:
            return std::make_shared<game::Probe>(game::Probe(1000, objType, *textures->getTexture("Probe"), location, 15, 1, 5, 5, owner));
        case game::ObjectType::Ranged:
            return std::make_shared<game::Ranged>(game::Ranged(50, objType, *textures->getTexture("Ranged"), location, 5, 5, 5, 2, owner));
        case game::ObjectType::Worker:
            return std::make_shared<game::Worker>(game::Worker(25, objType, *textures->getTexture("Worker"), location, 5, 1, 1, 1, owner));
        case game::ObjectType::AirBase:
        {
            // poznamka:
            // pocet materialov vstupujucich do konstruktorov pre budovy (ktore vedia stavat) oznacuje materialy potrebne na postavenie jednotky
            auto cost = config->GetCost("Ranged");
            return std::make_shared<game::AirBase>(game::AirBase(2500, objType, *textures->getTexture("AirBase"), location, cost["iron"], cost["copper"], cost["silicon"], owner));
        }
        case game::ObjectType::MilitaryBase:
        {
            auto cost = config->GetCost("Melee");
            return std::make_shared<game::MilitaryBase>(game::MilitaryBase(2500, objType, *textures->getTexture("MilitaryBase"), location, cost["iron"], cost["copper"], cost["silicon"], owner));
        }
        case game::ObjectType::Mine:
            return std::make_shared<game::Mine>(game::Mine(500, objType, *textures->getTexture("Mine"), location, 100, 100, 100, owner));
        case game::ObjectType::SpaceStation:
        {
            auto cost = config->GetCost("Worker");
            return std::make_shared<game::SpaceStation>(game::SpaceStation(10000, objType, *textures->getTexture("SpaceStation"), location, cost["iron"], cost["copper"], cost["silicon"], owner));
        }
        case game::ObjectType::Tower:
            return std::make_shared<game::Tower>(game::Tower(2000, objType, *textures->getTexture("Tower"), location, 0, 15, 10, 10, 1000, 1000, 1000, owner));
        default:
            throw "Invalid object!";
        }

        return nullptr;
    }
}