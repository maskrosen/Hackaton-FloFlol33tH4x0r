#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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

//Loads the map.
Map::Map(){
	size = 20;
	int blocks[][20] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
		{1,0,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,1,0,1,1,1,1,0,0,1,1,1,1,0,1,1,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
		{1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			mapBlocks[i][j] = blocks[i][j];
		}
	}

}

/*
* Get that memory back!!
*/
Map::~Map(){
	delete(mapBlocks);
}

/*
* Returns a 1 if there is a wall and 0 if it is a free path.
*/
int Map::getBlock(int x, int y){
	return mapBlocks[x][y];
}

/*
* Returns the maps length in blocks.
*/
int Map::mapSize(){
	return size;
}

