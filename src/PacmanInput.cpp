#include "PacmanInput.h"
#pragma once

PacmanInput::PacmanInput(Pacman* pacman)
{
	PacmanInput::pacman = pacman;
}

void PacmanInput::ProcessEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up)
		{
			
		}
	}
}