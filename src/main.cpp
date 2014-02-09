#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "Pacman.h"
#include "PacmanInput.h"
#pragma once

using namespace std;

int main()
{
	time_t startTime;
	time_t nowTime;
	time(&startTime);
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hackaton project FloFloL33tH4x0r");
    sf::CircleShape shape(150.f);
    shape.setFillColor(sf::Color::Blue);
	
	Pacman* pacman = new Pacman(30, 100.f, 200.f);
	PacmanInput* pacmanInput = new PacmanInput(pacman);

    while (window.isOpen())
    {
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
        window.clear();
      //  window.draw(shape);
		window.draw(pacman->getBody());
		window.draw(pacman->getMouth());

        window.display();
		time(&nowTime);
		double seconds = difftime(nowTime,startTime);
		cout << seconds << endl;
    }

    return 0;
}