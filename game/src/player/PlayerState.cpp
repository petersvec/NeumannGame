#include "../../include/player/PlayerState.hpp";

namespace game
{
	PlayerState::PlayerState()
	{
		initializePlayerState(2000, 2000, 2000, 1);
	}

	PlayerState::PlayerState(int iron, int copper, int silicon, unsigned char land)
	{
		initializePlayerState(iron, copper, silicon, land);
	}

	void PlayerState::initializePlayerState(int iron, int copper, int silicon, unsigned char land)
	{
		setIronBalance(iron);
		setCopperBalance(copper);
		setSiliconBalance(silicon);
		setLandConquered(land);
	}

	std::tuple<int, int, int, unsigned char> PlayerState::getPlayerState()
	{
		return std::make_tuple(getIronBalance(), getCopperBalance(), getSiliconBalance(), getLandConquered());
	}
}