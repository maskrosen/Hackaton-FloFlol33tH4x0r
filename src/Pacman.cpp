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

void Pacman::setDirection(Direction dir){
	direction = dir;
}

void Pacman::updateMouthDirection(){
	switch (direction) {
		case Direction::Up:
			mouth.setPoint(0, sf::Vector2f(xPos, yPos));
			mouth.setPoint(1, sf::Vector2f(xPos+radius, yPos+radius));
			mouth.setPoint(2, sf::Vector2f(xPos+radius*2, yPos));
			break;

		case Direction::Down:
			mouth.setPoint(0, sf::Vector2f(xPos, yPos+radius*2));
			mouth.setPoint(1, sf::Vector2f(xPos+radius, yPos+radius));
			mouth.setPoint(2, sf::Vector2f(xPos+radius*2, yPos+radius*2));
			break;

		case Direction::Left:
			mouth.setPoint(0, sf::Vector2f(xPos, yPos+radius/2));
			mouth.setPoint(1, sf::Vector2f(xPos+radius, yPos+radius));
			mouth.setPoint(2, sf::Vector2f(xPos, yPos+3*radius/2));
			break;

		case Direction::Right:
			mouth.setPoint(0, sf::Vector2f(xPos+radius*2, yPos+radius/2));
			mouth.setPoint(1, sf::Vector2f(xPos+radius, yPos+radius));
			mouth.setPoint(2, sf::Vector2f(xPos+radius*2, yPos+3*radius/2));
			break;
	}
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

Direction Pacman::getDirection(void){
	return direction;
}

Pos Pacman::getNextPos(){
	Pos p = Pos(xPos, yPos);
	switch (direction) {
		case Direction::Up:
			return p.add(Pos(0,-PACMAN_SPEED));
			break;

		case Direction::Down:
			return p.add(Pos(0,PACMAN_SPEED));
			break;

		case Direction::Left:
			return p.add(Pos(-PACMAN_SPEED,0));
			break;

		case Direction::Right:
			return p.add(Pos(PACMAN_SPEED,0));
			break;
		default:
			return p;
	}
	updateMouthDirection();
}