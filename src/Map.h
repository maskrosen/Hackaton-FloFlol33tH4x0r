#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "Pos.h"
#define TILE_WIDTH 30;
/*
* A class representing the map. It is built up with blocks (1) and free space (0).
*/
class Map {
	
public:
	Map();
	~Map();
	int getBlock(int, int);
	int mapSize();
	sf::RectangleShape getShape(int, int);
	Pos getPacmanStartPos(void);
private:
	Pos pacmanStartPos;
	void loadMap();
	void destroyMap();
	int size;
	int mapBlocks [20][20];
	sf::RectangleShape mapShapes [20][20];
};