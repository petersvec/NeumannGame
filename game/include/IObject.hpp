#pragma once
#include <SFML\Graphics\Sprite.hpp>

namespace game
{
	class IObject
	{
	private:

	protected:
		unsigned char m_type;
		sf::Sprite m_sprite;

	public:
		virtual unsigned char getType() = 0;
		sf::Sprite getSprite()
		{
			return m_sprite;
		}

		virtual void setType(unsigned char type) = 0;

		void setSprite(const sf::Texture& texture)
		{
			m_sprite.setTexture(texture);
			m_sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
		}
	};
}