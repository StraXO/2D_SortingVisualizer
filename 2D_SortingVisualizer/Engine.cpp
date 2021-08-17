#include "Engine.h"
#include "Events.h"
#include "Sorter.h"

Engine* Engine::s_Instance = nullptr;
Sorter sorter;

Engine::Engine():RenderWindow(sf::VideoMode(DISPLAY_WIDTH, DISPLAY_HEIGHT), WINDOW_NAME)
{
	//this->setVerticalSyncEnabled(true);
}

void Engine::events()
{
	Events::handleEvents(s_Instance);
}

void Engine::init()
{
	sorter.createObjects();
}

void Engine::render()
{
	this->display();
	this->clear();
}

void Engine::update()
{
	sorter.update();
}

void Engine::clean()
{
	s_Instance = nullptr;
}

