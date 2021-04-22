#pragma once

#include "JsonParser.hpp"
#include "ObjectManager.hpp"
#include "../../game/include/Tile.hpp"
#include <memory>

namespace engine
{
	static sf::Vector2u ScreenToTile(const sf::Vector2f& position)
	{
		return sf::Vector2u(position.x / config->getTileSize(), position.y / config->getTileSize());
	}

	static sf::Vector2f TileToScreen(const sf::Vector2u& position)
	{
		return sf::Vector2f(position.x * config->getTileSize(), position.y * config->getTileSize());
	}

	static unsigned short TileDistance(const sf::Vector2f& position1, const sf::Vector2f& position2)
	{
		double x = position2.x - position1.x;
		double y = position2.y - position1.y;
		unsigned char tileSize = config->getTileSize();

		return sqrt( x * x + y * y) / tileSize;
	}

	static std::pair<unsigned short, unsigned short> GetNearestFreeLocation(std::shared_ptr<game::Tile> location, std::shared_ptr<ObjectManager> objMan)
	{
		int x = location->getPosition().x/config->getTileSize();
		int y = location->getPosition().y/config->getTileSize();
		for (int k = 1; k < config->getMapWidth(); ++k)
		{
			for (int i = (-k); i <= k; ++i)
			{
				for (int j = (-k); j <= k; ++j)
				{	
					if (objMan->findUnit(x + i, y + j, game::Ownership::Player1) == nullptr &&
						objMan->findUnit(x + i, y + j, game::Ownership::Player2) == nullptr)
					{
						if (x + i < 0 ||
							x + i >= config->getMapHeight()||
							y + j < 0 ||
							y + j >= config->getMapWidth())
						{
							break;
						}

						return std::make_pair(x + i, y + j);
					}
				}
			}
		}
	}
}
