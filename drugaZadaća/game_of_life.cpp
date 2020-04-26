#include "game_of_life.h"

void game_of_life::kopiraj_generaciju()
{
	for (int x = 0; x < STUPACA; x++)
	{
		for (int y = 0; y < REDAKA; y++)
		{
			_kopija_generacije[x][y] = _trenutna_generacija[x][y];
		}

	}
}

void game_of_life::slucajna_vrijednost() 
{
	srand(time(NULL));
	int nPrecentChanse;

	for (int x = 3; x < STUPACA-3; x++)
	{
		for (int y = 3; y < REDAKA-3; y++)
		{
			nPrecentChanse= rand() % postotakToBeAlive + 1;
			if (nPrecentChanse == 1)
			{
				_trenutna_generacija[y][x] = true;
			}
		}
	}
}



game_of_life::game_of_life()
{
	slucajna_vrijednost();
}

void game_of_life::sljedeca_generacija()
{
	kopiraj_generaciju();

	for (int x = 3; x < STUPACA-3; x++)
	{
		for (int y = 3; y < REDAKA-3; y++)
		{
			int ITS_ALIVE = 0;

			for (int i = -1; i < 2; i++)//skenira sve oko sebe i Gledi ko je ALIVEE!  
			{
				
				
				for (int j = -1; j < 2; j++)
				{
					/*if (y + j < 0 || y + j >(REDAKA -1)) // BREAK, ITS A NONO, WORONG VALUE BOI
					{
						break;
					}
					if (x + i < 0 || x + i >(STUPACA-1))//BREAK, ITS A NONO, WORONG VALUE BOI
					{
						break;
					}*/
					if (!(i == 0 && j == 0))// kad ne gleda sebe
					{
						if (_kopija_generacije[x + i][y + j]==true)
						{
							++ITS_ALIVE;
						}
					}
				}
			}
			if (ITS_ALIVE == 2 || ITS_ALIVE == 3)
			{
				_trenutna_generacija[x][y] = true;
			}
			else
			{
				_trenutna_generacija[x][y] = false;
			}
		}

	}

}

void game_of_life::iscrtaj()
{
	
	for (int x = 0; x < STUPACA; x++)
	{
		for (int y = 0; y < REDAKA; y++)
		{
			if (_trenutna_generacija[x][y]==true)
			{
				cout << " 0 ";
			}
			else
			{
				cout << " - ";
			}
			if (y==REDAKA-1)
			{
				cout << endl;
			}
		}
	}
}
