#include <SFML/Graphics.hpp>
#include "DIrection.h"
#pragma once

class Pacman {

private:
    int radius;
	float xPos, yPos;
	Direction direction;
	sf::CircleShape body;
	sf::ConvexShape mouth;
public:
    Pacman(int, float, float);
	sf::CircleShape Pacman::getBody();
	sf::ConvexShape Pacman::getMouth();
	void Pacman::setDirection(Direction);
	void Pacman::update(float);
};