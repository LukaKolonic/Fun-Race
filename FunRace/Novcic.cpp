#include "Novcic.h"

Novcic::Novcic(sf::Vector2f size)
{
	novcic.setSize(size);
	novcic.setFillColor(sf::Color::Yellow);
	
}


void Novcic::nacrtaj(sf::RenderWindow& window)
{
	window.draw(novcic);
}

sf::FloatRect Novcic::getGlobalBounds()
{
	return novcic.getGlobalBounds();
}

void Novcic::setPos(sf::Vector2f newPos)
{
	novcic.setPosition(newPos);
}

sf::Vector2f Novcic::getPos()
{
	return novcic.getPosition();
}


