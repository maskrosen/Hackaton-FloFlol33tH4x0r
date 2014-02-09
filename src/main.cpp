#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	time_t startTime;
	time_t nowTime;
	time(&startTime);
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hackaton project FloFloL33tH4x0r");
    sf::CircleShape shape(150.f);
    shape.setFillColor(sf::Color::Blue);
	

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
		time(&nowTime);
		double seconds = difftime(nowTime,startTime);
		cout << seconds << endl;
    }

    return 0;
}