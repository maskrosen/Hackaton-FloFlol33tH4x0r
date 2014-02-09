#include <SFML/Graphics.hpp>
#pragma once

class Pacman {

private:
    int radius;
	float xPos, yPos;
	sf::CircleShape body;
	sf::ConvexShape mouth;
public:
    Pacman(int, float, float);
	sf::CircleShape Pacman::getBody();
	sf::ConvexShape Pacman::getMouth();
	void Pacman::move(float, float);
	void Pacman::update();
};