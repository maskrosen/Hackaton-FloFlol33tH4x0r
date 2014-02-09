#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "Map.h"
#pragma once

using namespace std;

//Loads the map.
Map::Map(){
	size = 20;
	pacmanStartPos = Pos(-1, -1);
	int blocks[][20] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,4,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,4,1},
		{1,0,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,1,4,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,1,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,1,0,1,1,1,1,2,2,1,1,1,1,0,1,1,0,1},
		{1,0,0,0,0,1,2,2,3,2,2,3,2,2,1,0,0,0,0,1},
		{1,0,0,0,0,1,2,2,2,3,3,2,2,2,1,0,0,0,0,1},
		{1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,1,1,0,1,1,5,1,1,1,0,1,1,0,1,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1},
		{1,0,1,0,0,0,0,0,0,4,1,0,0,0,0,0,0,1,0,1},
		{1,0,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,0,1},
		{1,4,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,4,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			mapBlocks[i][j] = blocks[j][i];
			sf::RectangleShape b;
			b.setSize(sf::Vector2f(30,30)); //TODO: TILE_WIDTH
			b.setPosition((float)(i*30),(float)(j*30)); //TODO: TILE_WIDTH
			switch (mapBlocks[i][j]) {
				case 0:
					b.setFillColor(sf::Color::Black);
					break;
				case 1:
					b.setFillColor(sf::Color::Blue);
					break;
				case 2:
					b.setFillColor(sf::Color(50, 50, 50, 255)); // grey
					break;
				case 3:
					b.setFillColor(sf::Color(50, 50, 50, 255)); // grey
					break;
				case 4:
					b.setFillColor(sf::Color::Yellow);
					break;
				case 5:
					pacmanStartPos = Pos(i, j);
					b.setFillColor(sf::Color::Black);
					break;
			}
			mapShapes[i][j] = b;
		}
	}

}

/*
* Get that memory back!!
*/
Map::~Map(){
	delete(mapBlocks);
	delete(mapShapes);
}

/*
* Returns an id for the given block.
* 0 = Free space with food item
* 1 = wall
* 2 = Free space
* 3 = Ghost
* 4 = Powerup 
* 5 = Pacman
*/
int Map::getBlock(int x, int y){
	return mapBlocks[x][y];
}

Pos Map::getPacmanStartPos(void){
	return Pos(9, 13);
}

/*
* Returns the maps length in blocks.
*/
int Map::mapSize(){
	return size;
}

/*
*	Returns the shape for the given block
*/
sf::RectangleShape Map::getShape(int x, int y){
	return mapShapes[x][y];
}
