#pragma once
#include <SFML/Graphics.hpp>

class Teleportacija
{
public:

	Teleportacija(float pozicijax, float pozicijay, sf::Color color);

	void nacrtaj(sf::RenderWindow& window);

	sf::Vector2f getPos();

	

	sf::FloatRect getGlobalBounds();


private:

	sf::RectangleShape	teleportacija;

};

