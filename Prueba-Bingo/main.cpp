#include <iostream> 
#include "Carton.h"
#include "Bolsa.h"

using namespace std;

Carton carton;
Bolsa bolsa;
int points;

int main()
{
	bool game_finished = false;
	points = 0;

	cout << "Welcome to BINGO! \n";
	cout << "\n";

	while (!game_finished)
	{
		carton.InitCarton();
		bolsa.InitBolsa();

		cout << "This is your Bingo Card:" << '\n';
		carton.PrintCarton();
		cout << "\n";
		cout << "Press any key to play. Good Luck!" << '\n';
		cin.get();
		for (int i = 0; i < 30; i++)
		{
			cout << "Number " << i + 1 << ": ";
			carton.CheckNumber(bolsa.PlayNumber());
		}
		cout << "\n";
		int prize = carton.CheckPrize();
		if (prize > 0)
		{
			if (prize >= 3)
			{
				points += 1500;
				cout << "You won 1500 Credits!" << '\n';
			}
			
			else
			{
				points += 10;
				cout << "You won 10 Credits!" << '\n';
			}
		}
		cout << "\n";
		cout << "Current Amount of Credits: " << points << "\n";
		cout << "\n";
		cout << "Do you want to play again? (y/n) ";
		char play_again;
		cin >> play_again;
		if (play_again != 'y')
			game_finished = true;
	}
	
	return 0;
}