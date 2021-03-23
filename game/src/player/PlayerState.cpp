#include "../../include/player/PlayerState.hpp";

namespace game
{
	PlayerState::PlayerState()
	{
		initializePlayerState(2000, 2000, 2000);
	}

	PlayerState::PlayerState(int iron, int copper, int silicon)
	{
		initializePlayerState(iron, copper, silicon);
	}

	void PlayerState::initializePlayerState(int iron, int copper, int silicon)
	{
		setIronBalance(iron);
		setCopperBalance(copper);
		setSiliconBalance(silicon);
	}

	std::tuple<int, int, int> PlayerState::getPlayerState()
	{
		return std::make_tuple(getIronBalance(), getCopperBalance(), getSiliconBalance());
	}
}