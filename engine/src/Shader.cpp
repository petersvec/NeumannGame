#include "../include/Shader.hpp"
#include <SFML\Graphics\Shader.hpp>


namespace engine
{
	Shader::Shader()
	{

	}

	void Shader::doStuff()
	{
		sf::Shader shader;

		if (!shader.loadFromFile("data/shaders/storm.vert", sf::Shader::Vertex))
		{
			// error...
		}

		// load only the fragment shader
		if (!shader.loadFromFile("data/shaders/blink.frag", sf::Shader::Fragment))
		{

		}
	}

}
