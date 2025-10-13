#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int RandomNumber(int from, int to) {
	int number = 0;
	//              % (how many possible numbers) + offset
	// Example  from 1 to 5 	
	// Example [1,2,3,4,5] (5 possible numbers)
	// Beacuse Modulus always starts from 0  (and here ends at 4 [0-4] the 5 possible values we got from before)
	// We add a 1 (the from number) to each number to turn it from 
	// [0,1,2,3,4] -> [1,2,3,4,5]
	number = rand() % (to - from + 1) + from;

	return number;
}

int main()
{
	srand((unsigned)time(NULL));

	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;


	return 0;
}