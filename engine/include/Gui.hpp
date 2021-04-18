#pragma once
#include "IObject.hpp"
#include <SFML/Graphics.hpp>
namespace engine
{
	class Gui
	{
	public:
		Gui();

		void LoadObject(IObjectPtr);
		sf::Font font;
		sf::Text text;
	};
}