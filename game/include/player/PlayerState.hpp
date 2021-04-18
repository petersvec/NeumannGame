#pragma once
#include <memory>
#include <tuple>

namespace game
{
	class PlayerState
	{
	private:
		int m_ironBalance;
		int m_copperBalance;
		int m_siliconBalance;
		int m_landConquered;

	protected:

	public:
		PlayerState();
		PlayerState(int, int, int, int);
		void initializePlayerState(int, int, int, int);
		void updatePlayerLandConquered();
		void updatePlayerBalances(int, int, int);
		std::tuple<int, int, int, int> getPlayerState();

		void updateLand(int value)
		{
			m_landConquered += value;
		}

		int getIronBalance()
		{
			return m_ironBalance;
		}

		void setIronBalance(int iron)
		{
			m_ironBalance = iron;
		}

		int getCopperBalance()
		{
			return m_copperBalance;
		}

		void setCopperBalance(int copper)
		{
			m_copperBalance = copper;
		}

		int getSiliconBalance()
		{
			return m_siliconBalance;
		}

		void setSiliconBalance(int silicon)
		{
			m_siliconBalance = silicon;
		}

		void setLandConquered(int land)
		{
			m_landConquered = land;
		}

		int getLandConquered()
		{
			return m_landConquered;
		}
	};
}