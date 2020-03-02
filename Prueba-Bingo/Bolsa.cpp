#include "Bolsa.h"



Bolsa::Bolsa()
{
	InitBolsa();
}


Bolsa::~Bolsa()
{
}

void Bolsa::InitBolsa()
{
	initial_bolsa.clear();
	playing_bolsa.clear();

	for (int i = 0; i < 60; i++)
	{
		initial_bolsa.push_back(i + 1);
	}

	for (int i = 0; i < 30; i++)
	{
		int number_id = rand() % (initial_bolsa.size() - 1);
		int number_to_play = initial_bolsa[number_id];

		playing_bolsa.push_back(number_to_play);

		initial_bolsa.erase(initial_bolsa.begin() + number_id);
	}
}

int Bolsa::PlayNumber()
{
	int number_id = 0;

	if (playing_bolsa.size() > 1)
		int number_id = rand() % (playing_bolsa.size() - 1);

	int played_number = playing_bolsa[number_id];

	playing_bolsa.erase(playing_bolsa.begin() + number_id);

	cout << played_number << '\n';

	return played_number;
}
