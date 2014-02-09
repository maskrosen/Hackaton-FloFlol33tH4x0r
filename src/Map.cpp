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
			mapBlocks[i][j] = blocks[i][j];
			sf::RectangleShape b;
			b.setSize(sf::Vector2f(10,10));
			if (mapBlocks[i][j]) {
				b.setFillColor(sf::Color::Black);
			} else {
				b.setFillColor(sf::Color::Yellow);
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

/*
* Returns the maps length in blocks.
*/
int Map::mapSize(){
	return size;
}

/*
*	Returns an array with blocks
*/
sf::RectangleShape* Map::getShape(int x, int y){
	return &(mapShapes[x][y]);
}
