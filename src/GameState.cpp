
#include "GameState.h"



GameState::GameState(void) {
}

void GameState::initFood(void) {
	int score = 10;
	int radius = 10;
	float x = 10.f;
	float y = 20.f;
	
	for (int i = 0; i < 100; i++) {
		GameState::food[i] = FoodItem::FoodItem(100,20,x,y);
	}
}


