#pragma once

class Pos{
private:
	int x;
	int y;
public:
	Pos(int, int);
	Pos();
	int getX();
	int getY();
	Pos add(Pos);
};