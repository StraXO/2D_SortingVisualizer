#pragma once
#include "Engine.h"

class Events
{
public:
	static void handleEvents(Engine* window);
	
	static Events* instance()
	{
		if (s_Instance)
			return s_Instance;
		return s_Instance = new Events;
	}
private:
	static Events* s_Instance;
};
