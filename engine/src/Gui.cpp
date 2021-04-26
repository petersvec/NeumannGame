#include "../include/Gui.hpp"
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include "../include/JsonParser.hpp"

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

	void Gui::LoadObject(std::shared_ptr<IObject> object, game::Ownership activePlayer)
	{
		text.setPosition(150, 630);
		text.setCharacterSize(15);
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
		if (object->getIsBuilding() == true && object->getOwner()==activePlayer)
		{
			str = str + '\n' + "Press 1 to build an unit " + CreateUnitCostString(object);
		}
		if (object->getName() == "Worker" && object->getOwner() == activePlayer)
		{
			str += "\n";
			str += "1: SpaceStation" + CreateBuildingCostString("SpaceStation") + " | ";
			str += "2: MilitaryBase" + CreateBuildingCostString("MilitaryBase") + " | ";
			str += "3: AirBase" + CreateBuildingCostString("AirBase") + "\n";
			str += "4: Mine" + CreateBuildingCostString("Mine") + " | ";
			str += "5: Tower" + CreateBuildingCostString("Tower");
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

	std::string Gui::CreateUnitCostString(std::shared_ptr<IObject> unit)
	{
		if (unit->getType() != game::ObjectType::Tower && unit->getType() != game::ObjectType::Mine)
		{
			auto cost = config->GetCost(unit->getBuildUnitName());
			return "(" + unit->getBuildUnitName() + " - " + std::to_string(cost["iron"]) + "/" + std::to_string(cost["copper"]) + "/" + std::to_string(cost["silicon"]) + ")";
		}
		else return "";
	}

	std::string Gui::CreateBuildingCostString(const std::string& unit) const
	{
		auto cost = config->GetCost(unit);
		return "(" + std::to_string(cost["iron"]) + "/" + std::to_string(cost["copper"]) + "/" + std::to_string(cost["silicon"]) + ")";
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
	void Gui::setMapText(int x, int y, engine::TilePtr tile)
	{
		m_mapText.setPosition(0, 0);
		m_mapText.setCharacterSize(20);
		m_mapText.setFont(font);
		std::string mapstr = "";
		mapstr = "X: " + std::to_string(x) + "\nY: " + std::to_string(y) + "\nType: " + tile->getTypeString() + "\nMinerals: " + std::to_string(tile->getMinerals());
		m_mapText.setString(mapstr);


	}
	sf::Text Gui::getMapText()
	{
		return m_mapText;
	}
}