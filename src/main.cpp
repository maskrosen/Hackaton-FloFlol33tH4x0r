#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pacman.h"
#include "PacmanInput.h"
#include "Map.h"
#include <time.h>
#include "Ghost.h"
#pragma once

using namespace std;


sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Hackaton project FloFloL33tH4x0r");

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

int main()
{
	/* Variables gg */
	float tDiff = 0;
	float mouthTimer = 0;
	clock_t tNow;
	clock_t tLast = 0;

	Map map;

	//Zhe amaaaaazing Game Loop
    while (window->isOpen())
    {
		//Update time
		tNow = clock();
		tDiff = (float(tNow - tLast))/CLOCKS_PER_SEC;
		tLast = tNow;
		printf ("%f sec, %d clicks.\n",((float)tNow)/CLOCKS_PER_SEC,tNow);

		handleEvents();

		pacman->update((float)tDiff);

		/* Draw Stuff */
        window->clear();

		// window.draw(shape);
		for (int i = 0; i< map.mapSize(); i++) {
			for (int j = 0; j< map.mapSize(); j++) {
				window->draw(map.getShape(i,j));
			}
		}
		window->draw(pacman->getBody());
		
		mouthTimer+=tDiff;
		if(mouthTimer>=0.25){
			window->draw(pacman->getMouth());
		}
		if(mouthTimer>=0.5){			
			mouthTimer=0;
		}

		window->draw(ghost->getBody());
		window->draw(ghost->getHead());
		window->draw(ghost->getLeg1());
		window->draw(ghost->getLeg2());
		window->draw(ghost->getLeg3());
		window->draw(ghost->getLeg4());
		window->draw(ghost->getEye1());
		window->draw(ghost->getEye2());
		window->draw(ghost->getEyeP1());
		window->draw(ghost->getEyeP2());


        window->display();
    }

    return 0;
}