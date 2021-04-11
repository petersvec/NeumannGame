#include "../include/Gui.hpp"
#include <SFML/Graphics/Text.hpp>
#include <iostream>

namespace engine
{
	Gui::Gui()
	{

	}

	void Gui::LoadObject(IObjectPtr object)
	{
		font.loadFromFile("data/fonts/OpenSans-Bold.ttf");
		text.setPosition(500, 640);
		text.setCharacterSize(20);
		text.setFont(font);
		text.setString(object->getName());	 
	}

}