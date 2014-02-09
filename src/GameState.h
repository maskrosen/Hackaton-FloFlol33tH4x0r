#pragma once
#include "FoodItem.h"

class GameState
{
private:
	FoodItem food[100];

public:
	GameState(void);
	~GameState(void);
	void initFood(void);
};

