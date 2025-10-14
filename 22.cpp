#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int ReadPositiveNumber(string message) {
	int number = 0;
	do {
		cout << message << endl;

		cin >> number;
	} while (number <= 0);


	return number;

}

vector<int> ReadArray(short length) {

	vector<int> numbers;


	for (int i = 1; i <= length; i++) {
		string message = "Enter Item Number [" + to_string(i) + "] : ";

		numbers.push_back(ReadPositiveNumber(message));
	}

	return numbers;
}

short CheckFrequncyInArray(vector<int> array, short number) {
	short frequency = 0;
	for (int i = 0; i <= array.size() - 1; i++) {

		if (number == array[i]) {
			frequency++;
		}


	}

	return frequency;
}

void PrintArray(vector<int> array) {
	cout << " original array : ";
	for (int i = 0; i <= array.size() - 1; i++) {

		cout << array[i] << " ";


	}
	cout << endl;
}

int main()
{

	short lengthOfArray = ReadPositiveNumber("Enter How Many Elements You Want");

	vector<int> array = ReadArray(lengthOfArray);

	PrintArray(array);
	short numberToCheck = ReadPositiveNumber("Enter The Number You Want To Check Its Frequncy");

	cout << "the frequncy of the number" << numberToCheck << " : " << CheckFrequncyInArray(array, numberToCheck) << endl;

	return 0;
}