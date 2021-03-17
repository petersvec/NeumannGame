#pragma once
#include <SFML\Graphics\Sprite.hpp>
#include "../../game/include/ObjectType.hpp"

namespace engine
{
	class IObject
	{
	private:

	protected:
		game::ObjectType m_type;
		sf::Sprite m_sprite;

		IObject(game::ObjectType type, const sf::Texture& texture)
			:
			m_type{ type },
			m_sprite{}
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

		void setType(game::ObjectType type)
		{
			m_type = type;
		}

		void setSprite(const sf::Texture& texture)
		{
			m_sprite.setTexture(texture);
			m_sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
		}
	};
}