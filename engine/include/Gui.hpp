#pragma once
#include "IObject.hpp"
#include <SFML/Graphics.hpp>

#include "../../game/include/player/PlayerState.hpp"

namespace engine
{
	class Gui
	{
	public:
		Gui();

		void LoadObject(std::shared_ptr<IObject>, game::Ownership);
		sf::Font font;
		sf::Text text;

		sf::Text GetPlayerStateText();

		void SetPlayerState(game::PlayerState& state);
		void setMapText(int x, int y, engine::TilePtr tile);
		sf::Text getMapText();
		sf::Font& GetFont();
	private:
		sf::Text m_player_state_text;
		sf::Text m_mapText;
	};
}