#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>



class Novcic
{
public:

	Novcic(sf::Vector2f size);

	void nacrtaj(sf::RenderWindow& window);

	sf::FloatRect getGlobalBounds();


	void setPos(sf::Vector2f newPos);

	sf::Vector2f getPos();

	

private:

	sf::RectangleShape	novcic;

};

