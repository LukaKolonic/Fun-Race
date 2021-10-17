#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Auto.h"

using namespace std;

class Policija
{
public:
~Policija();

	Policija(string Slika);

	void nacrtajPoliciju(sf::RenderWindow& window);

	void movePolicija(char smjer, float brzina);

	bool Sudar(Auto igrac);


private:

	sf::Texture Tekstura;
	sf::Sprite Sprite;

};

