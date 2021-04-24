#pragma once
#include "Map.hpp"
#include "Utilities.hpp"
#include "../../game/include/ObjectType.hpp"
#include "../../game/include/player/PlayerState.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

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
		game::Ownership m_owner;
		bool m_isBuilding = false;

		IObject(unsigned short hp, game::ObjectType type, const sf::Texture& texture, TilePtr location, game::Ownership owner)
			:
			m_hp{ hp },
			m_type{ type },
			m_sprite{},
			m_owner{ owner }

		{
			setSprite(texture);
			setLocation(location);
		}

	public:
		virtual void attack(std::shared_ptr<IObject>, std::shared_ptr<ObjectManager>) = 0;
		virtual void move(TilePtr, game::PlayerState&) = 0;
		virtual unsigned char getMoveSpeed() = 0;

		virtual void draw(sf::RenderWindow* window)
		{
			if (m_owner == game::Ownership::Player1)
			{
				m_sprite.setColor(sf::Color::Red);
			}
			else
			{
				m_sprite.setColor(sf::Color::Blue);
			}

			window->draw(m_sprite);
		}

		void setOwner(game::Ownership player)
		{
			m_owner = player;
		}

		game::Ownership getOwner() const
		{
			return m_owner;
		}

		void setPosition(const sf::Vector2u& position)
		{
			m_sprite.setPosition(TileToScreen(position));
		}

		sf::Vector2f getPosition() const
		{
			return m_sprite.getPosition();
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

		bool getIsBuilding()
		{
			return m_isBuilding;
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
			m_sprite.setPosition(location->getPosition());
		}
		virtual std::string getName()
		{
			return "null";
		}
	};
}