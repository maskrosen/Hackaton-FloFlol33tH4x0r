#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Pos.h"
#pragma once

class Pacman {
private:
    float radius;
	float xPos, yPos;
	float PACMAN_SPEED;
	float mouthTimer;
	Direction direction;
	sf::CircleShape body;
	sf::ConvexShape mouth;
	void Pacman::updateMouthDirection();
  public:
    Pacman (float, float);
	void draw(sf::RenderWindow* window, float deltaTime);
	sf::CircleShape Pacman::getBody();
	sf::ConvexShape Pacman::getMouth();
	void Pacman::setDirection(Direction);
	void Pacman::update(float);
	Direction getDirection(void);
	Pos getNextPos();

};