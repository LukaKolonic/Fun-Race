#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Novcic.h"
#include "Teleportacija.h"

using namespace std;

class Auto
{

public:
   ~Auto();
        
    Auto(string Slika);
     

    void nacrtajAuto(sf::RenderWindow& window);
       
    
    void moveAuto(char smjer, float brzina);

    
    bool Skupljanje(Novcic coin);

    sf::FloatRect getGlobalBounds();

    sf::Vector2f getPos();

    void setPos(sf::Vector2f newPos);

    bool Skupljanje(Teleportacija teleportacija);
      
   
private:
    sf::Texture Tekstura;
    sf::Sprite Sprite;



};

