#include <SFML/Graphics.hpp>
#include "Engine.h"

int main()
{
	Engine::instance()->init();
	
	while (Engine::instance()->isOpen())
	{
		Engine::instance()->update();
		Engine::instance()->events();
		Engine::instance()->render();
	}
	
	Engine::instance()->clean();

	return 0;
}
