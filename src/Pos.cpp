#include "Pos.h"

Pos::Pos(int x, int y){
	Pos::x = x;
	Pos::y = y;
}

Pos::Pos(){
	x = -1;
	y = -1;
}

int Pos::getX(){
	return x;
}

int Pos::getY(){
	return y;
}

Pos Pos::add(Pos p){
	return Pos(x+p.getX(), y+p.getY());
}