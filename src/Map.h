#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
/*
* A class representing the map. It is built up with blocks (1) and free space (0).
*/
class Map {
	
public:
	Map(){};
	~Map(){};
	int getBlock(int, int);
	int mapSize();
private:
	void loadMap();
	void destroyMap();
	int size;
	int mapBlocks [20][20];
};