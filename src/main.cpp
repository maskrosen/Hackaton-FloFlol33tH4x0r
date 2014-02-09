#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pacman.h"
#include <time.h>

using namespace std;

int main()
{
	/* Variables gg */
	clock_t tStart;
	clock_t tNow;

	tStart = clock();

    sf::RenderWindow window(sf::VideoMode(800, 600), "Hackaton project FloFloL33tH4x0r");
    sf::CircleShape shape(150.f);
    shape.setFillColor(sf::Color::Blue);
	
	Pacman pacman(30,100.f,200.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		/* Draw Stuff */
        window.clear();
      //  window.draw(shape);
		window.draw(pacman.getBody());
		window.draw(pacman.getMouth());

        window.display();

		tNow = clock();
		float tDiff = tNow-tStart;
		printf ("%f sec, %d clicks.\n",((float)tNow)/CLOCKS_PER_SEC,tNow);
    }

    return 0;
}