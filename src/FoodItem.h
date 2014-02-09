#pragma once
#include <SFML/Graphics.hpp>
class FoodItem
{
private:
	int score;
	int radius;
	float xPos, yPos;
	sf::CircleShape body; //TODO: make this a pointer and add a destructor?

public:
	FoodItem (int, int, float, float);
	int FoodItem::getScore(void);
	sf::CircleShape FoodItem::getBody();
};

