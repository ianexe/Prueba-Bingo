#include "Carton.h"


Carton::Carton()
{
	InitCarton();
}


Carton::~Carton()
{
}

//Resets Carton Values
void Carton::InitCarton()
{
	vector<int> used_numbers;

	for (int i = 0; i < 3; i++)
	{
		for (int t = 0; t < 5; t++)
		{
			carton_numbers[t][i] = (rand() % 60) + 1;

			while (IsNumberRepeated(used_numbers, carton_numbers[t][i]))
			{
				carton_numbers[t][i] = (rand() % 60) + 1;
			}

			used_numbers.push_back(carton_numbers[t][i]);
			carton_bools[t][i] = false;
		}
	}
}

//Print all Carton numbers
void Carton::PrintCarton()
{
	for (int i = 0; i < 3; i++)
	{
		for (int t = 0; t < 5; t++)
		{
			cout << carton_numbers[t][i] << " ";
		}
		cout << "\n";
	}
}

//Print line
void Carton::PrintLine(int line)
{
	for (int t = 0; t < 5; t++)
	{
		cout << carton_numbers[t][line] << " ";
	}
	cout << "\n";
}

//Checks if number is in Carton
void Carton::CheckNumber(int number)
{
	for (int i = 0; i < 3; i++)
	{
		for (int t = 0; t < 5; t++)
		{
			if (carton_numbers[t][i] == number)
			{
				carton_bools[t][i] = true;
				return;
			}
		}
	}
}

//Checks if Carton won a Line or a Bingo
int Carton::CheckPrize()
{
	//Return Value, 0 is no Prize, 1-2 is Line, 3 is Bingo
	int prize = 0;
	int line_id;

	for (int i = 0; i < 3; i++)
	{
		int won_numbers = 0;
		for (int t = 0; t < 5; t++)
		{
			if (carton_bools[t][i])
				won_numbers++;

			if (won_numbers >= 5)
			{
				prize++;
				line_id = i;
			}	
		}
	}

	if (prize >= 3)
		cout << "Congratulations, you have a BINGO!" << '\n';

	if (prize < 3 && prize > 0)
	{
		cout << "Congratulations, you have a LINE!" << '\n';
		cout << "Your winner Line is: ";
		PrintLine(line_id);
	}

	if (prize <= 0)
	{
		cout << "Good luck next time..." << '\n';
	}

	return prize;
}

//Checks if number is repeated in repeated_list
bool Carton::IsNumberRepeated(vector<int> repeated_list, int number)
{
	for (int i = 0; i < repeated_list.size(); i++)
	{
		if (repeated_list[i] == number)
			return true;
	}
	return false;
}
