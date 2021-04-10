#include "IObject.hpp"
namespace engine
{
	class Gui
	{
	public:
		Gui();

		void LoadObject(sf::Window&, IObjectPtr);
	};
}