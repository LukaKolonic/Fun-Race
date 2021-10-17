#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Auto.h"
#include "Policija.h"
#include "Novcic.h"
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
#include <string>
#include <fstream>
#include <list>
#include "Teleportacija.h"
#include <queue>

using namespace std;
using namespace chrono;

int main()
{
	//POCETNI EKRAN
	sf::RenderWindow window(sf::VideoMode(800, 600), "FunRace");

	sf::Clock sat;
	sf::Time vrijeme; //TRENUTNO VRIJEME
	vrijeme = sat.getElapsedTime();

	Menu menu(window.getSize().x, window.getSize().y); //VELICINA MENIJA

	window.setFramerateLimit(60);
	
	cout << "UCITAVANJE IGRICE......." << endl;

	// POZADINA IGRICE-CESTA
	sf::Texture texture;
	if (!texture.loadFromFile("Road.png")) {
		std::cout << "404" << std::endl;
	}
	sf::Sprite sprite;
	sf::Vector2u size = texture.getSize();
	sprite.setTexture(texture);
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(400.f, 300.f);

	//POZADINA GAME OVER
	sf::Texture t;
	if (!t.loadFromFile("GameOver.jpg")) {
		std::cout << "404" << std::endl;
	}
	sf::Sprite s;
	s.setTexture(t);

	//POCETNI SCORE
	int score = 0;

	//FONT MENI
	sf::Font font;
	if (!font.loadFromFile("Car.ttf")) {
		std::cout << "404" << std::endl;
	}

	// SS-PRETVARAC
	stringstream ssScore;
	ssScore << "Score: " << score;

	sf::Text TextScore;
	TextScore.setCharacterSize(30);
	TextScore.setPosition( 10, 10 );
	TextScore.setFont(font);
	TextScore.setString(ssScore.str());
	TextScore.setFillColor(sf::Color::Red);

	// PAUZA/RESUME
	string ssPauza = "Pauza";
	string ssResume = "Resume";
	

	sf::Text pauzaText;
	pauzaText.setCharacterSize(40);
	pauzaText.setPosition(310, 240);
	pauzaText.setFont(font);
	pauzaText.setString(ssPauza);

	sf::Text resumeText;
	resumeText.setCharacterSize(40);
	resumeText.setPosition(310, 240);
	resumeText.setFont(font);
	resumeText.setString(ssResume);

	//FORMULA/POLICIJA
	Auto  igrac("Auto.png");
	Policija neprijatelj("Police.png");

	//TELEPORTACIJA
	Teleportacija teleportacija1(542, 155, sf::Color::Blue);
	Teleportacija teleportacija2(120, 500, sf::Color::Red);
	queue <Teleportacija> queue;
	queue.push(teleportacija1);
	queue.push(teleportacija2);


	srand(time(nullptr));

	//NOVCICI
	vector<Novcic>novcic;
	Novcic novcic1({ 15 , 10 });

	//RANDOM NOVCICI
	sf::Time vrijeme1;
	sf::Clock sat1;
	sf::Time vrijeme2 = sf::seconds(3);

	
	bool pauza = false;

	//POCETAK MJERENJA BIN DAT
	auto begin = chrono::high_resolution_clock::now();

	ifstream citanje("BDat.bin", ios_base::binary);
	if (!citanje) {
		std::cout << "404";
		return 1;
	}


	while (true)
	{
		int duljina;
		if(!citanje.read((char*)&duljina, sizeof(duljina))) {
			break;
		}
		char* tmp = new char[duljina];
		citanje.read(tmp, duljina);
		string str(tmp, duljina);
		delete[] tmp;
	}
	
	citanje.close();
	//KRAJ MJERENJA BIN DAT
	auto end = chrono::high_resolution_clock::now();
	cout << "Ucitavanje binarne dat :" << duration_cast<nanoseconds>(end - begin).count() << "ns" << std::endl;

	
	//UPUTE ZA IGRANJE
	std::cout << "UPUTE ZA IGRICU FUNRACE : " << std::endl;
	std::cout << "Igra je namjenjena za 2 igraca! (forumala se pomice sa W,S,A,D, a policija strelicama)" << std::endl;
	std::cout << "Glavni cilj igre formulom pobjeci od policije,te pritom skupiti sto vise novcica " << std::endl;
	std::cout << "HINT ZA FORMULU! (teleportacija sa plavog na crveni kvadratic)" << std::endl;
	std::cout << "P = pauza, R = resume" << std::endl;
	std::cout << "Histogram se pojavljuje u cmd nakon odigrane igre!" << std::endl;

	//LISTA ZA HISTOGRAM
	list<int> lista;

		while (window.isOpen())
		{
			sf::Event event;
			
			while (window.pollEvent(event))
			{
				
				if (event.type == sf::Event::Closed)

					window.close();

				switch (event.type)


				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case::sf::Keyboard::Up: //KRETANJE PO MENIJU
						menu.Gore();
						break;

					case::sf::Keyboard::Down:
						menu.Dole();
						break;

					case sf::Keyboard::Return:
						switch (menu.Enter())
						{
						case 1:
							//PROZOR IGRICE
							std::cout << "POKRENI IGRU" << std::endl;
							window.create(sf::VideoMode(800, 600), "FunRunIgra");
							while (window.isOpen())
							{
								sf::Event event1;
								while (window.pollEvent(event1)) 
								{

									if (event1.type == sf::Event::Closed)
										window.close();
									switch (event1.type)
									{
									case sf::Event::Closed:
										window.close();
										break;
									}
									//PAUZA
									if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
										pauza= true;
										
									}
									//RESUME
									if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
									{
										pauza = false;
									}


									if(!pauza)
									{
										//KRETANJE IGRACA-FORMULE
									if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
										igrac.moveAuto('u', 25);
									}
									else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
										igrac.moveAuto('d', 25);
									}
									else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
										igrac.moveAuto('l', 25);
									}
									else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
										igrac.moveAuto('r', 25);

									}
									//KRETANJE PLICIJE

									if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
										neprijatelj.movePolicija('u', 25);
									}
									else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
										neprijatelj.movePolicija('d', 25);
									}
									else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
										neprijatelj.movePolicija('l', 25);
									}
									else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
										neprijatelj.movePolicija('r', 25);

									}

									
									//RANDOM NOVCICI
										vrijeme1 += sat1.restart();

										while (vrijeme1 >= vrijeme2) {

											int Posx = rand() % (700 - 200 + 1) + 200;
											int Posy = rand() % (500 - 150 + 1) + 150;
											novcic1.setPos(sf::Vector2f((float)Posx, (float)Posy));
											novcic.push_back(novcic1);
											vrijeme1 -= vrijeme2;

										}


										//BRISANJE NOVCICA
										for (int i = 0; i < novcic.size(); i++)
										{
											if (novcic[i].getPos().y > window.getSize().y)
											{
												novcic.erase(novcic.begin() + i);
											}


										}


										//TELEPORTACIJA
										if (igrac.Skupljanje(queue.front()))
										{
											igrac.setPos(sf::Vector2f(queue.back().getPos().x, queue.back().getPos().y));

										}

										
										
										//SKUPLJENJE NOVCICA
										for (int i = 0; i < novcic.size(); i++) {
											if (igrac.Skupljanje(novcic[i])) {
												//POZICIJA NOVCICA ZA HISTOGRAM
												int xPos = novcic[i].getPos().x;
												int yPos = novcic[i].getPos().y;
												lista.push_back(xPos);
												lista.push_back(yPos);
												

												novcic[i].setPos({ 11111111, 11111 });
												score++;
												
												ssScore.str("");
												ssScore << "Score " << score;
												TextScore.setString(ssScore.str());


											}
											
										}
									}

								}

								//PISANJE U BIN DAT
								string st = "Rezultat: " + to_string(score);
								ofstream pisanje("BDat.bin", std::ios_base::binary);
								if (!pisanje) {
									cout << "404";
								}
								int duljina = st.length();
								pisanje.write((char*)&duljina, sizeof(duljina));
								pisanje.write(st.c_str(), duljina);
								pisanje.close();


								window.clear();

								window.draw(sprite); //CTRANJE CESTE

								igrac.nacrtajAuto(window);

								neprijatelj.nacrtajPoliciju(window);


								window.draw(TextScore);


							
								//TELEPORTACIJE
								queue.front().nacrtaj(window);
								queue.back().nacrtaj(window);
								
								//CRTANJE NOVCICA
								for (int i = 0; i < novcic.size(); i++)
								{
									novcic[i].nacrtaj(window);
								}

								//GAME OVER - SUDAR
								if (neprijatelj.Sudar(igrac)) {

									window.draw(s);
									pauza = true;
									window.draw(TextScore);
									
								}
								
								//PAUZA/TEKST

								if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
									
									window.draw(pauzaText);
								}
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
								{
									window.draw(resumeText);
								}
								

								window.display();

						
							}

							break;

						case 2:
							cout << "POSTAVKE" << std::endl;
							
							break;

						case 3:
							cout << "TOP LISTA" << std::endl;
							
							break;

						case 4:
							window.close();
							break;


						}

					}

				}

			}

			window.clear();

			//VRIJEME UCITAVANJA IGRICE
			sf::Time vrijeme1 = sf::seconds(5.5); 
			vrijeme = sat.getElapsedTime();

			if (vrijeme.asSeconds() >= vrijeme1.asSeconds())
			{
				menu.draw(window);
				window.display();

			}

			
		}


		//HISTOGRAM
		std::cout << "Histogram prethodne igre: " << std::endl;

		for (auto it = lista.begin(); it != lista.end(); ++it)
		{
			std::cout << "Pozicija skupljanja novcica: x(" << *it << "), y(";
			++it;
			std::cout  << *it << ") " << std::endl;
			
		}
	

	return 0;
}