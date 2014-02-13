#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pacman.h"
#include "PacmanInput.h"
#include "PacmanMap.h"
#include <time.h>
#include "Ghost.h"
#pragma once

using namespace std;

// Variables
sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Hackaton project FloFloL33tH4x0r");

PacManMap* pmMap = new PacManMap();
Pacman* pacman = new Pacman(100.f, 200.f);
PacmanInput* pacmanInput = new PacmanInput(pacman);
Ghost* ghost = new Ghost(30.f, 40.f, 200.f, 300.f, sf::Color::Red);

void handleEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			pacmanInput->ProcessEvent(event);
			break;
		}

	}
}

void update(float deltaTime)
{
	pacman->update(deltaTime);
}

void draw(sf::RenderWindow* window, float deltaTime)
{
	window->clear();

	// window.draw(shape);
	for (int i = 0; i< pmMap->mapSize(); i++) {
		for (int j = 0; j< pmMap->mapSize(); j++) {
			window->draw(pmMap->getShape(i,j));
		}
	}

	pacman->draw(window, deltaTime);

	ghost->draw(window, deltaTime);

	window->display();
}

int main()
{
	/* Time variables */
	float tDiff = 0;
	clock_t tNow;
	clock_t tLast = 0;

	//Zhe amaaaaazing Game Loop
    while (window->isOpen())
    {
		//Update time
		tNow = clock();
		tDiff = (float(tNow - tLast))/CLOCKS_PER_SEC;
		tLast = tNow;
		printf ("%f sec, %d clicks.\n",((float)tNow)/CLOCKS_PER_SEC,tNow);

		/* Handling events */
		handleEvents();

		/* Handle update in update function */
		update((float)tDiff);

		/* Draw Stuff */
		draw(window, (float)tDiff);
    }

    return 0;
}