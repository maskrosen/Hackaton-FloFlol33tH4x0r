#include "Pacman.h"
#pragma once

Pacman::Pacman(int r, float x, float y) {
	radius = r;
	xPos = x;
	yPos = y;
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

void Pacman::move(float x, float y)
{
	xPos += x;
	yPos += y;
}

void Pacman::update()
{
	body.setPosition(xPos, yPos);
	mouth.setPoint(0, sf::Vector2f(xPos, yPos+radius/2));
	mouth.setPoint(1, sf::Vector2f(xPos+radius, yPos+radius));
	mouth.setPoint(2, sf::Vector2f(xPos, yPos+3*radius/2));
}