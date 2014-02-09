#include "Ghost.h"
#pragma once
Ghost::Ghost (float w, float h, float x, float y, sf::Color color) {
	width = w;
	height = h;
	xPos = x;
	yPos = y;
	head.setRadius(width/2);
	head.setFillColor(color);
	head.setPosition(x,y);
	body.setSize(sf::Vector2f(width, height/3));
	body.setFillColor(color);
	body.setPosition(x,y+width/2);
	createLeg(0, &leg1, color);
	createLeg(1, &leg2, color);
	createLeg(2, &leg3, color);
	createLeg(3, &leg4, color);

	eye1.setRadius(width/7);
	eye1.setFillColor(sf::Color::White);
	eye1.setPosition(sf::Vector2f(xPos+width/7, yPos+width/5));

	eyeP1.setRadius(width/11);
	eyeP1.setFillColor(sf::Color::Black);
	eyeP1.setPosition(sf::Vector2f(xPos+width/6, yPos+width/4));

	eye2.setRadius(width/7);
	eye2.setFillColor(sf::Color::White);
	eye2.setPosition(sf::Vector2f(xPos+width-width/7*3, yPos+width/5));

	eyeP2.setRadius(width/11);
	eyeP2.setFillColor(sf::Color::Black);
	eyeP2.setPosition(sf::Vector2f(xPos+width-width/8*3, yPos+width/4));

		
}

void Ghost::createLeg(int legNumber, sf::ConvexShape* leg, sf::Color color){
	leg->setFillColor(color);	
	float yDif = width/2+height/3;
	leg->setPointCount(3);
	leg->setPoint(0, sf::Vector2f(xPos+width/4*legNumber,  yPos+yDif));
	leg->setPoint(1, sf::Vector2f(xPos+width/4*(legNumber+1),  yPos+yDif));
	leg->setPoint(2, sf::Vector2f(xPos+width/4*(legNumber+0.5), yPos+yDif+height/5));
}

sf::RectangleShape Ghost::getBody(){
	return body;
}

sf::CircleShape Ghost::getHead(){
	return head;
}

sf::ConvexShape Ghost::getLeg1(){
	return leg1;
}

sf::ConvexShape Ghost::getLeg2(){	
	return leg2;
}

sf::ConvexShape Ghost::getLeg3(){	
	return leg3;
}

sf::ConvexShape Ghost::getLeg4(){	
	return leg4;
}

sf::CircleShape Ghost::getEye1(){
	return eye1;
}

sf::CircleShape Ghost::getEye2(){
	return eye2;
}

sf::CircleShape Ghost::getEyeP1(){
	return eyeP1;
}

sf::CircleShape Ghost::getEyeP2(){
	return eyeP2;
}