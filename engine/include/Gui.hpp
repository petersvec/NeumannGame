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

		void LoadObject(std::shared_ptr<IObject>);
		sf::Font font;
		sf::Text text;

		sf::Text GetPlayerStateText();

		void SetPlayerState(game::PlayerState& state);
		sf::Font& GetFont();
	private:
		sf::Text m_player_state_text;
	};
}