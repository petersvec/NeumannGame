#pragma once

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

#include "../../game/include/ObjectType.hpp"
#include "Map.hpp"
#include "Utilities.hpp"

namespace engine
{
	class IObject
	{
	private:

	protected:
		unsigned short m_hp;
		game::ObjectType m_type;
		sf::Sprite m_sprite;
		TilePtr m_location;

		IObject(unsigned short hp, game::ObjectType type, const sf::Texture& texture, TilePtr location)
			:
			m_hp{ hp },
			m_type{ type },
			m_sprite{},
			m_location{ location }
		{
			setSprite(texture);
		}

	public:
		virtual void draw(sf::RenderWindow* window)
		{
			window->draw(m_sprite);
		}

		virtual void update()
		{

		}

		void setPosition(const sf::Vector2u& position)
		{
			m_sprite.setPosition(TileToScreen(position));
		}

		unsigned short getHp()
		{
			return m_hp;
		}

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

		void setHp(unsigned short hp)
		{
			m_hp = hp;
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