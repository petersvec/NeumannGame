#include "../include/UnitFactory.hpp"
#include "../include/TextureHandler.hpp"

namespace engine
{
    UnitFactoryPtr unitFactory = std::make_unique<UnitFactory>();

    engine::IObjectPtr UnitFactory::create(game::ObjectType objType, TilePtr location, game::Ownership owner)
    {
        sf::Texture texture;

        switch (objType)
        {
        case game::ObjectType::Melee:
            return std::make_shared<game::Melee>(game::Melee(100, objType, *textures->getTexture("Melee"), location, 1, 5, 5, owner));
        case game::ObjectType::Probe:
            return std::make_shared<game::Probe>(game::Probe(1000, objType, *textures->getTexture("Probe"), location, 15, 5, 5, owner));
        case game::ObjectType::Ranged:
            return std::make_shared<game::Ranged>(game::Ranged(50, objType, *textures->getTexture("Ranged"), location, 3, 5, 2, owner));
        case game::ObjectType::Worker:
            return std::make_shared<game::Worker>(game::Worker(25, objType, *textures->getTexture("Worker"), location, 5, 1, 1, owner));
        case game::ObjectType::AirBase:
            return std::make_shared<game::AirBase>(game::AirBase(2500, objType, *textures->getTexture("AirBase"), location, 1000, 1000, 1000, owner));
        case game::ObjectType::MilitaryBase:
            return std::make_shared<game::MilitaryBase>(game::MilitaryBase(2500, objType, *textures->getTexture("MilitaryBase"), location, 500, 500, 500, owner));
        case game::ObjectType::Mine:
            return std::make_shared<game::Mine>(game::Mine(500, objType, *textures->getTexture("Mine"), location, 100, 100, 100, owner));
        case game::ObjectType::SpaceStation:
            return std::make_shared<game::SpaceStation>(game::SpaceStation(10000, objType, *textures->getTexture("SpaceStation"), location, 5000, 5000, 5000, owner));
        case game::ObjectType::Tower:
            return std::make_shared<game::Tower>(game::Tower(2000, objType, *textures->getTexture("Tower"), location, 15, 10, 10, 1000, 1000, 1000, owner));
        default:
            throw "Invalid object!";
        }

        return nullptr;
    }
}