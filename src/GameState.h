#pragma once
#include "FoodItem.h"
#include "Pacman.h"

class GameState
{
private:
	FoodItem food[100];
	Pacman pacman;
	void updateGhosts(void);
public:
	GameState(void);
	~GameState(void);
	void initFood(void);
	void update(void);
};

