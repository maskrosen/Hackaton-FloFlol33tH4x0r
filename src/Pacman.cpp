#include "Pacman.h"
#pragma once

Pacman::Pacman (float x, float y) {
	radius = 12;
	xPos = x;
	yPos = y;
	PACMAN_SPEED = 70;
	body.setRadius(radius);
	body.setFillColor(sf::Color::Yellow);
	body.setPosition(x,y);
	mouth.setFillColor(sf::Color::Black);
	mouth.setPointCount(3);
	mouth.setPoint(0, sf::Vector2f(xPos, yPos+radius/2));
	mouth.setPoint(1, sf::Vector2f(xPos+radius, yPos+radius));
	mouth.setPoint(2, sf::Vector2f(xPos, yPos+3*radius/2));
}


sf::CircleShape Pacman::getBody(){
	return body;
}

sf::ConvexShape Pacman::getMouth(){
	return mouth;
}

void Pacman::setDirection(Direction dir)
{
	direction = dir;
}

void Pacman::update(float delta)
{
	int xDir = 0;
	int yDir = 0;
	switch (direction) {
		case Direction::Up:
			yDir = -1;
			break;

		case Direction::Down:
			yDir = 1;
			break;

		case Direction::Left:
			xDir = -1;
			break;

		case Direction::Right:
			xDir = 1;
			break;
	}
	xPos += PACMAN_SPEED*delta*xDir;
	yPos += PACMAN_SPEED*delta*yDir;
	body.setPosition(xPos, yPos);
	mouth.setPoint(0, sf::Vector2f(xPos, yPos+radius/2));
	mouth.setPoint(1, sf::Vector2f(xPos+radius, yPos+radius));
	mouth.setPoint(2, sf::Vector2f(xPos, yPos+3*radius/2));
}