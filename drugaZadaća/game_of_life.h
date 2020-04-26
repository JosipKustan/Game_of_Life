#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
	
using namespace std;

class game_of_life {
private:
	int postotakToBeAlive = 50; //1 od n šanse kad je = n da bude èelija alive

	static const unsigned int STUPACA = 30;
	static const unsigned int REDAKA = 30;

	bool _trenutna_generacija[REDAKA][STUPACA];
	bool _kopija_generacije[REDAKA][STUPACA];

	void kopiraj_generaciju();//kopira trenutnu u kopiju kako bi ih usporedili i mogli odma mjenjati
	void slucajna_vrijednost(); // generira alive polja ovisno o (postotakToBeAlive)
	

public:
	game_of_life();
	void sljedeca_generacija();//tjera sustav da dela
	void iscrtaj();//logièno
};


