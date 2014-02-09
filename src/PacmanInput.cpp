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
			pacman->setDirection(Direction::Up);
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			pacman->setDirection(Direction::Down);
		}
		else if (event.key.code == sf::Keyboard::Left)
		{
			pacman->setDirection(Direction::Left);
		}
		else if (event.key.code == sf::Keyboard::Right)
		{
			pacman->setDirection(Direction::Right);
		}
	}
}