
#include "GameState.h"



GameState::GameState(void) {
	m = &PacManMap();
	pacman = &Pacman(m->getPacmanStartPos().getX()*32, m->getPacmanStartPos().getY()*32);
	initFood();
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

void GameState::update(void){
	
	Pos p = pacman->getNextPos();
	if( m->getBlock(p.getX(), p.getY()) == 1 ){
		pacman->setDirection(Direction::None);
	}
	pacman->update(1.0);

}

