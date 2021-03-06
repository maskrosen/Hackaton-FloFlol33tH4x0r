#include "FoodItem.h"

FoodItem::FoodItem(int s, int r, float x, float y) {
	score = s;
	radius = r;
	xPos = x;
	yPos = y;
	body.setRadius(radius);
	body.setFillColor(sf::Color::White);
	body.setPosition(x,y);
}

FoodItem::FoodItem(void) {
	score = 10;
	radius = 10;
	xPos = 10.f;
	yPos = 10.f;
}

int FoodItem::getScore(void) {
	return score;
}

sf::CircleShape FoodItem::getBody(){
	return body;
}


