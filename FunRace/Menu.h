#pragma once
#include <SFML/Graphics.hpp>
#define BROJ_STAVKI 5


class Menu
{
public:


	Menu(float sirina, float visina);

	~Menu();

	void draw(sf::RenderWindow& window);
	void Gore();
	void Dole();
	int Enter();



private:


	int Menu_odabir;
	sf::Font font;
	sf::Text menu[BROJ_STAVKI];


};






