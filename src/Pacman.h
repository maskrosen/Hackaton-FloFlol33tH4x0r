#include <SFML/Graphics.hpp>
#include "Direction.h"
#pragma once

class Pacman {

private:
    int radius;
	float xPos, yPos;
	float PACMAN_SPEED;
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