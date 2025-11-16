#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


int myAbsolute(int number) {
	if (number >= 0)
		return number;
	else
		return number * -1;
}


int main()
{

	cout << myAbsolute(-11) << endl;
	cout << abs(-11) << endl;


	return 0;
}