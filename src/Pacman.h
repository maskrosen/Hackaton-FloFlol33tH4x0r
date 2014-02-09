#include <SFML/Graphics.hpp>
class Pacman {
    int radius;
	float xPos, yPos;
	sf::CircleShape body;
	sf::ConvexShape mouth;
  public:
    Pacman (int, float, float);
	sf::CircleShape Pacman::getBody();
	sf::ConvexShape Pacman::getMouth();
};