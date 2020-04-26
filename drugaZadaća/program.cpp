#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;

//zadnji tren sam se sjetil da stavim probabilty da èelija bude alive.. ako hocete u classi je variabla za promjenu sad je na 1 u 50 èelija bude alive

int main() {
	game_of_life the_game;
	int brojIteracija;
	int izbor=0;
	
	
	while (!(izbor==1||izbor==2))
	{
		cout << "Klikajte za prikaz generaciji po generaciji = 1" << endl;
		cout << "Upis broja iteracija generacija = 2" << endl;
		cin >> izbor;
	}
	if (izbor==1)
	{
		bool dalje;
		do {
			the_game.iscrtaj();
			the_game.sljedeca_generacija();
		
			cout << "Dalje (1/0): ";
			cin >> dalje;
		} while (dalje);

	}
	if (izbor == 2)
	{
		cout << "Koliko iteracija generacija: ";
		cin >> brojIteracija;
		for (int i = 0; i < brojIteracija; i++)
		{
			the_game.iscrtaj();
			the_game.sljedeca_generacija();
			system("cls");
		}
		
	}

	return 0;
}