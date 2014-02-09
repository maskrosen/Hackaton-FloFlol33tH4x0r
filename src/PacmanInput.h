#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pacman.h"
#pragma once

class PacmanInput {
	
public:
    PacmanInput(Pacman* pacman);
	void ProcessEvent(sf::Event event);

private:
	Pacman* pacman;
};