#include "../include/Gui.hpp"
#include <SFML/Graphics/Text.hpp>
#include <iostream>

namespace engine
{
	Gui::Gui()
	{
		font.loadFromFile("data/fonts/OpenSans-Bold.ttf");

		m_player_state_text.setString("");
		m_player_state_text.setPosition(10, 630);
		m_player_state_text.setCharacterSize(15);
		m_player_state_text.setFillColor(sf::Color::White);
		m_player_state_text.setFont(font);
	}

	void Gui::LoadObject(std::shared_ptr<IObject> object)
	{
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
		if (object->getIsBuilding() == true)
		{
			str = str + '\n' + "Press 1 to build an unit";
		}
		text.setString(str);
	}

	sf::Font& Gui::GetFont()
	{
		return font;
	}
	
	sf::Text Gui::GetPlayerStateText()
	{
		return m_player_state_text;
	}

	void Gui::SetPlayerState(game::PlayerState& state)
	{
		std::string state_str = "";
		auto [iron, copper, silicon, land] = state.getPlayerState();

		state_str += "Land: " + std::to_string(land) + "\n";
		state_str += "Iron: " + std::to_string(iron) + "\n";
		state_str += "Copper: " + std::to_string(copper) + "\n";
		state_str += "Silicon: " + std::to_string(silicon) + "\n";

		m_player_state_text.setString(state_str);
	}
}