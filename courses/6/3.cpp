#include <iostream>
#include <vector>
#include "../../libs/MyLib.h"
using namespace std;
using namespace Input;
using namespace Output;
vector<int> FillArrayWithRandomNumbers(short length) {

	vector<int> numbers;


	for (int i = 1; i <= length; i++) {

		short random = RandomNumber(1, 100);
		numbers.push_back(random);
	}

	return numbers;
}
int main() {
	SeedRandomness();

	int length = ReadNumber("Enter the length of array");
	vector<int> array = FillArrayWithRandomNumbers(length);

	for (int i : array) {
		cout << i << endl;
	}


	return 0;
}