#pragma once

#include <SFML/Graphics.hpp>

constexpr auto DISPLAY_WIDTH = 1600;
constexpr auto DISPLAY_HEIGHT = 800;
constexpr auto WINDOW_NAME = "Sorting Algorithm Visualizer";

class Engine final : public sf::RenderWindow
{
public:
	void events();
	void update();
	void render();
	void clean();
	void init();

	static Engine* instance()
	{
		if (s_Instance) return s_Instance;
		return s_Instance = new Engine;
	}

private:
	Engine();
	static Engine* s_Instance;
};
