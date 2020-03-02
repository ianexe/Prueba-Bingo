#include <iostream> 
#include <vector>

using namespace std;

class Bolsa
{
private:
	vector<int> initial_bolsa;
	vector<int> playing_bolsa;

public:
	Bolsa();
	~Bolsa();

	void InitBolsa();

	int PlayNumber();
};

