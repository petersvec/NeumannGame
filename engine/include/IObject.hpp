#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include "../../game/include/ObjectType.hpp"
#include "../../game/include/Tile.hpp"
using TilePtr = std::shared_ptr<game::Tile>;

namespace engine
{
	class IObject
	{
	private:

	protected:
		game::ObjectType m_type;
		sf::Sprite m_sprite;
		TilePtr m_location;

		IObject(game::ObjectType type, const sf::Texture& texture, TilePtr location)
			:
			m_type{ type },
			m_sprite{},
			m_location{ location }
		{
			setSprite(texture);
		}

	public:
		game::ObjectType getType()
		{
			return m_type;
		}

		sf::Sprite getSprite()
		{
			return m_sprite;
		}

		TilePtr getLocation()
		{
			return m_location;
		}

		void setType(game::ObjectType type)
		{
			m_type = type;
		}

		void setSprite(const sf::Texture& texture)
		{
			m_sprite.setTexture(texture);
			m_sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
		}

		void setLocation(TilePtr location)
		{
			m_location = location;
		}
	};
}