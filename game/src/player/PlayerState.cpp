#include "../../include/player/PlayerState.hpp";

namespace game
{
	PlayerState::PlayerState()
	{
		initializePlayerState(2000, 2000, 2000, 1);
	}

	PlayerState::PlayerState(int iron, int copper, int silicon, int land)
	{
		initializePlayerState(iron, copper, silicon, land);
	}

	void PlayerState::initializePlayerState(int iron, int copper, int silicon, int land)
	{
		setIronBalance(iron);
		setCopperBalance(copper);
		setSiliconBalance(silicon);
		setLandConquered(land);
	}

	void PlayerState::updatePlayerBalances(int iron, int copper, int silicon)
	{
		setIronBalance(getIronBalance() + iron);
		setCopperBalance(getCopperBalance() + copper);
		setSiliconBalance(getSiliconBalance() + silicon);
	}

	std::tuple<int, int, int, int> PlayerState::getPlayerState()
	{
		return std::make_tuple(getIronBalance(), getCopperBalance(), getSiliconBalance(), getLandConquered());
	}

	void PlayerState::updatePlayerLandConquered()
	{
		setLandConquered(getLandConquered() + 1);
	}
}