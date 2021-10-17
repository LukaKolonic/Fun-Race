#include "Menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

Menu::Menu(float sirina, float visina)
{

	
	menu[0].setFont(font);
	menu[0].setOutlineThickness(15.f);
	menu[0].setOutlineColor(sf::Color::Green);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setString("FUN RACE");
	menu[0].setPosition(sf::Vector2f(sirina / 3, visina / (BROJ_STAVKI + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("POKRENI IGRU");
	menu[1].setPosition(sf::Vector2f(sirina / 4, visina / (BROJ_STAVKI + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("POSTAVKE");
	menu[2].setPosition(sf::Vector2f(sirina / 3, visina / (BROJ_STAVKI + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("TOP LISTA");
	menu[3].setPosition(sf::Vector2f(sirina / 3, visina / (BROJ_STAVKI + 1) * 4));


	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("IZADI");
	menu[4].setPosition(sf::Vector2f(sirina / 2.3, visina / (BROJ_STAVKI + 1) * 5));

	Menu_odabir = 0;

	if (!font.loadFromFile("Car.ttf"))
	{
		cout << "404" << endl;
	}
}



Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < BROJ_STAVKI; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::Gore()
{
	if (Menu_odabir - 1 >= 0)
	{
		menu[Menu_odabir].setFillColor(sf::Color::White);
		Menu_odabir--;
		menu[Menu_odabir].setFillColor(sf::Color::Red);
	}
}



void Menu::Dole()
{
	if (Menu_odabir + 1 < BROJ_STAVKI)
	{
		menu[Menu_odabir].setFillColor(sf::Color::White);
		Menu_odabir++;
		menu[Menu_odabir].setFillColor(sf::Color::Red);

		
	}

	
}

int Menu::Enter()
{
	
	return Menu_odabir;
	
}

