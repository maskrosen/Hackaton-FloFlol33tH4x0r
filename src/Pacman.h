#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Pos.h"
#pragma once

class Pacman {

private:
    float radius;
	float xPos, yPos;
	float PACMAN_SPEED;
	Direction direction;
	sf::CircleShape body;
	sf::ConvexShape mouth;
  public:
    Pacman (float, float);
	sf::CircleShape Pacman::getBody();
	sf::ConvexShape Pacman::getMouth();
	void Pacman::setDirection(Direction);
	void Pacman::update(float);
	Direction getDirection(void);
	Pos getNextPos();
};