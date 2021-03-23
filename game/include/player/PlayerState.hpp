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

	protected:

	public:
		PlayerState();
		PlayerState(int, int, int);
		void initializePlayerState(int, int, int);
		std::tuple<int, int, int> getPlayerState();

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
	};
}