#include "Auto.h"
#include <SFML/Graphics.hpp>
#include "Teleportacija.h"

Auto::~Auto()
{
}

Auto::Auto(string Slika)
{
    if (!Tekstura.loadFromFile(Slika)) {
        cout << "404" << endl;
    }
    Sprite.setTexture(Tekstura);
    Sprite.setScale(0.7f, 0.7f);
    Sprite.setPosition(300.f, 500.f);
    Sprite.setRotation(-90);
}

void Auto::nacrtajAuto(sf::RenderWindow& window)
{
    window.draw(Sprite);

}

void Auto::moveAuto(char smjer, float brzina)
{
    if (smjer == 'u') {
        Sprite.move(0, -brzina);
    }
    else if (smjer == 'd') {
        Sprite.move(0, brzina);
    }
    else if (smjer == 'l') {
        Sprite.move(-brzina, 0);
    }
    else if (smjer == 'r') {
        Sprite.move(brzina, 0);
    }
}

bool Auto::Skupljanje(Novcic coin)
{
    if (Sprite.getGlobalBounds().intersects(coin.getGlobalBounds()))//AKO SE SIJEKU GRANICE
    {
        return true;
    }
    
    return false;

}

sf::FloatRect Auto::getGlobalBounds()
{
    return Sprite.getGlobalBounds();
}

sf::Vector2f Auto::getPos()
{
   
        return Sprite.getPosition();
    
}

void Auto::setPos(sf::Vector2f newPos)
{
    Sprite.setPosition(newPos);
}

bool Auto::Skupljanje(Teleportacija teleportacija)
{
    if (Sprite.getGlobalBounds().intersects(teleportacija.getGlobalBounds()))
    {
        return true;
    }

    return false;

}



    

   