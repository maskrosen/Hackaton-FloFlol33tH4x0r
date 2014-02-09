#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "Pacman.h"

using namespace std;

int main()
{
	time_t startTime;
	time_t nowTime;
	time(&startTime);
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
        window.clear();
      //  window.draw(shape);
		window.draw(pacman.getBody());
		window.draw(pacman.getMouth());

        window.display();
		time(&nowTime);
		double seconds = difftime(nowTime,startTime);
		cout << seconds << endl;
    }

    return 0;
}