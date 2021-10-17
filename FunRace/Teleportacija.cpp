#include "Teleportacija.h"

Teleportacija::Teleportacija(float pozicijax, float pozicijay, sf::Color color)
{
	
	teleportacija.setSize(sf::Vector2f(40.f, 10.f));
	teleportacija.setPosition(pozicijax, pozicijay);
	teleportacija.setFillColor(sf::Color(color));
	teleportacija.setOutlineColor(sf::Color::Black);
	teleportacija.setOutlineThickness(5.f);
}

void Teleportacija::nacrtaj(sf::RenderWindow& window)
{
	window.draw(teleportacija);
}

sf::Vector2f Teleportacija::getPos()
{
	return teleportacija.getPosition();
}


sf::FloatRect Teleportacija::getGlobalBounds()
{
	return teleportacija.getGlobalBounds();
}
