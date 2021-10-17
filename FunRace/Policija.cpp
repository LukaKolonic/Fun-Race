#include "Policija.h"
#include "Auto.h"

Policija::~Policija()
{
}

Policija::Policija(std::string Slika)
{
    if (!Tekstura.loadFromFile(Slika)) {
        cout << "404" << endl;
    }
    Sprite.setTexture(Tekstura);
    Sprite.setScale(0.7f, 0.7f);
    Sprite.setPosition(400.f, 100.f);
   

}

void Policija::nacrtajPoliciju(sf::RenderWindow& window)
{
    window.draw(Sprite);

}

void Policija::movePolicija(char smjer, float brzina)
{

    if (smjer == 'u') {
        Sprite.move(0,-brzina);
    }
    else if (smjer == 'd') {
        Sprite.move(0, brzina);
    }
    else if (smjer== 'l') {
        Sprite.move(-brzina,0);
    }
    else if (smjer== 'r' ) {
        Sprite.move(brzina, 0);
    }

}

bool Policija::Sudar(Auto igrac)
{
    if (Sprite.getGlobalBounds().intersects(igrac.getGlobalBounds()))
    {
        return true;
    }

    return false;
}
