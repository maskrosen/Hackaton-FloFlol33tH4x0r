#pragma once
#include "FoodItem.h"
#include "Pacman.h"
#include "Map.h"

class GameState
{
private:
	FoodItem food[100];
	Pacman pacman;
	Map m;
public:
	GameState(void);
	~GameState(void);
	void initFood(void);
	void update(void);
};

