#include <SFML/Graphics.hpp>
class Ghost {
    float width, height;
	float xPos, yPos;
	sf::CircleShape head;
	sf::RectangleShape  body;
	sf::ConvexShape leg1;
	sf::ConvexShape leg2;
	sf::ConvexShape leg3;
	sf::ConvexShape leg4;
	sf::ConvexShape* legs;
	sf::CircleShape eye1;
	sf::CircleShape eye2;	
	sf::CircleShape eyeP1;
	sf::CircleShape eyeP2;


	public:
		Ghost (float, float, float, float, sf::Color);
		sf::RectangleShape Ghost::getBody();
		sf::CircleShape Ghost::getHead();
		sf::ConvexShape Ghost::getLeg1();
		sf::ConvexShape Ghost::getLeg2();
		sf::ConvexShape Ghost::getLeg3();
		sf::ConvexShape Ghost::getLeg4();
		sf::CircleShape Ghost::getEye1();
		sf::CircleShape Ghost::getEye2();		
		sf::CircleShape Ghost::getEyeP1();
		sf::CircleShape Ghost::getEyeP2();

	private:
		void Ghost::createLeg(int, sf::ConvexShape*, sf::Color);
};