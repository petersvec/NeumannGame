#include "../../include/player/PlayerState.hpp";

namespace game
{
	PlayerState::PlayerState()
	{
		initializePlayerState(100, 100, 100, 0);
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

	bool PlayerState::checkBalance(int iron, int copper, int silicon)
	{
		if (m_ironBalance < iron || m_copperBalance < copper || m_siliconBalance < silicon) {
			return false;
		}
		
		return true;
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