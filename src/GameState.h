#pragma once
#include "FoodItem.h"
#include "Pacman.h"
#include "PacManMap.h"
#include "Pos.h"

class GameState{
private:
	FoodItem food[100];
	Pacman* pacman;
	PacManMap* m;
public:
	GameState(void);
	~GameState(void);
	void initFood(void);
	void update(void);
};

