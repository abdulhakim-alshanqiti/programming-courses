#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
int RandomNumber(int from, int to) {
	return rand() % (to - from + 1) + from;
}

int ReadPositiveNumber(string message) {
	int number = 0;
	do {
		cout << message << endl;

		cin >> number;
	} while (number <= 0);


	return number;

}




void PrintArray(vector<int> array, string message) {

	if (array.size() == 0) {
		message += "Empty";
	}

	cout << message;


	for (int i = 0; i < array.size(); i++) {

		cout << array[i] << "\t";


	}
	cout << "\n\n";



}

void AddArrayElement(vector<int>& array, int number) {

	array.push_back(number);
}


vector<int> FillArrayWithRandomNumbers(short length) {

	vector<int> numbers;


	for (int i = 1; i <= length; i++) {

		short random = RandomNumber(-100, 100);
		numbers.push_back(random);
	}

	return numbers;
}
int CountPositiveNumbersInArray(vector<int> array) {
	int counter = 0;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] >= 0)
			counter++;
	}

	return counter;
}

int main()
{
	srand((unsigned)time(NULL));
	short number = ReadPositiveNumber("Enter a number");
	vector<int> array = FillArrayWithRandomNumbers(number);

	PrintArray(array, "Array 1 Elements: \n");
	int positiveNumbersCount = CountPositiveNumbersInArray(array);

	cout << "the number of positive numbers : " << positiveNumbersCount << endl;


	return 0;
}