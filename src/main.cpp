#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pacman.h"
#include "PacmanInput.h"
#include <time.h>
#pragma once

using namespace std;

int main()
{
	/* Variables gg */
	clock_t tDiff = 0;
	clock_t tNow;
	clock_t tLast = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Hackaton project FloFloL33tH4x0r");
    sf::CircleShape shape(150.f);
    shape.setFillColor(sf::Color::Blue);
	
	Pacman* pacman = new Pacman(30, 100.f, 200.f);
	PacmanInput* pacmanInput = new PacmanInput(pacman);


	//Zhe amaaaaazing Game Loop
    while (window.isOpen())
    {
		//Update time
		tNow = clock();
		tDiff = tNow - tLast;
		tLast = tNow;
		printf ("%f sec, %d clicks.\n",((float)tNow)/CLOCKS_PER_SEC,tNow);

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					pacmanInput->ProcessEvent(event);
					break;
			}

        }

		/* Draw Stuff */
        window.clear();
      //  window.draw(shape);
		window.draw(pacman->getBody());
		window.draw(pacman->getMouth());

        window.display();
    }

    return 0;
}