#include "../include/Planet.hpp"

namespace game
{
	Planet::Planet()
	{
		m_owner = Ownership::Unoccupied;
	}

	Ownership Planet::getOwner()
	{
		return m_owner;
	}
}