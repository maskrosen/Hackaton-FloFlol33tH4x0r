#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Map {
public:
	Map(int level){loadMap(level);};
	int getBlock(int, int);
	int mapSize();
private:
	void loadMap(int level);
	int xLength;
	int yLength;
	int mapBlocks[20][20];
};

void Map::loadMap(int level){
	xLength = 20;
	yLength = 20;

	string line;
	ifstream file;
	int i = 0;

	file.open("level"+level);
	while ( getline(file, line) ) {
		for(int j = 0; j < yLength; j++){
			mapBlocks [i][j] = line[j] - '0';
		}
		i++;
	}
}


int Map::getBlock(int x, int y){
	return mapBlocks[x][y];
}

int Map::mapSize(){
	return xLength;
}

