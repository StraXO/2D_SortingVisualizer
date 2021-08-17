#include "Sorter.h"
#include "Events.h"

const int pillar_count = 200;

sf::RectangleShape pillars[pillar_count];
static bool is_complete = false;

bool Sorter::isComplete()
{
	return is_complete;
}

void Sorter::createObjects()
{
	for (auto i = 0; i <= pillar_count - 1; i++)
	{
		sf::RectangleShape pillar(sf::Vector2f(DISPLAY_WIDTH / pillar_count, rand() % (DISPLAY_HEIGHT - 1) + 1));
		pillar.setPosition(sf::Vector2f(i * DISPLAY_WIDTH / pillar_count, 0));
		pillar.setFillColor(sf::Color::White);
		pillar.setOutlineColor(sf::Color::Black);
		pillar.setOutlineThickness(1.0f);

		pillars[i] = pillar;
	}
}


void Sorter::sort()
{	
	for (auto i = 0; i <= pillar_count - 2; i++)
	{
		// Change the pillar's positions if the current pillar is bigger in height then the next pillar, 
		if (pillars[i].getSize().y > pillars[i + 1].getSize().y)
		{
			// Swapping the object's properties using a temp var.
			const auto temp_pillar_size = pillars[i].getSize();
			pillars[i].setSize(pillars[i + 1].getSize());
			pillars[i + 1].setSize(temp_pillar_size);

			// Stop this loop if any pillar has changed position
			break;
		}
	}
}

void Sorter::checkIfComplete()
{
	is_complete = true;

	for (auto i = 0; i <= pillar_count - 2; i++){
		if (pillars[i].getSize().y > pillars[i + 1].getSize().y)
		{
			is_complete = false;
			
			// If at any point, it is not sorted correctly, stop this loop
			break;
		}
	}
}

void Sorter::drawObjects()
{
	// Draw all pillars
	for (const auto& pillar : pillars)
		Engine::instance()->draw(pillar);
}

void Sorter::update()
{
	// Sort until all pillars are sorted correctly
	if (!is_complete){
		sort();
		checkIfComplete();
	}

	drawObjects();
}

