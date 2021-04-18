#include "../include/Gui.hpp"
#include <SFML/Graphics/Text.hpp>
#include <iostream>

namespace engine
{
	Gui::Gui()
	{

	}

	void Gui::LoadObject(std::shared_ptr<IObject> object)
	{
		font.loadFromFile("data/fonts/OpenSans-Bold.ttf");
		text.setPosition(500, 640);
		text.setCharacterSize(20);
		text.setFont(font);
		std::string player;
		if (object->getOwner() == game::Ownership::Player1)
		{
			player = "| Owner: Player 1";
		}
		else
		{
			player = "| Owner: Player 2";
		}
		

		std::string str = object->getName() + "| HP: " + std::to_string(object->getHp());
		str = str + player;
		text.setString(str);	 
	}

}