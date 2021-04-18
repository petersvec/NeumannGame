#pragma once
#include "IObject.hpp"
#include <SFML/Graphics.hpp>
namespace engine
{
	class Gui
	{
	public:
		Gui();

		void LoadObject(std::shared_ptr<IObject>);
		sf::Font font;
		sf::Text text;
	};
}