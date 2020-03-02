#include <iostream> 
#include <array>
#include <vector>

using namespace std;

class Carton
{
private:
	array<array<int, 3>, 5> carton_numbers;
	array<array<bool, 3>, 5> carton_bools;

public:
	Carton();
	~Carton();

	void InitCarton();
	void PrintCarton();
	void PrintLine(int line);

	void CheckNumber(int number);
	int CheckPrize();

private:
	bool IsNumberRepeated(vector<int> repeated_list, int number);
};

