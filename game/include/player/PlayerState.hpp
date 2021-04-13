#pragma once
#include <tuple>

namespace game
{
	class PlayerState
	{
	private:
		int m_ironBalance;
		int m_copperBalance;
		int m_siliconBalance;
		unsigned char m_landConquered;

	protected:

	public:
		PlayerState();
		PlayerState(int, int, int, unsigned char);
		void initializePlayerState(int, int, int, unsigned char);
		void updatePlayerLandConquered();
		void updatePlayerBalances(int, int, int);
		std::tuple<int, int, int, unsigned char> getPlayerState();

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

		void setLandConquered(unsigned char land)
		{
			m_landConquered = land;
		}

		unsigned char getLandConquered()
		{
			return m_landConquered;
		}
	};
}