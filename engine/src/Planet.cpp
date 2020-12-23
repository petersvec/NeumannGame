#include "../include/Planet.hpp"

namespace engine
{
	Planet::Planet()
	{
		m_owner = (unsigned char)0;
	}

	unsigned char Planet::getOwner()
	{
		return m_owner;
	}
}