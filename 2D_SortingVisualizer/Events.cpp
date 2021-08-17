#include "Events.h"
#include <SFML/Window.hpp>

Events* Events::s_Instance = nullptr;

void Events::handleEvents(Engine* window)
{
	sf::Event event{};

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		default:
			break;
		}
	}
}
