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

vector<int> FillArrayWithRandomNumbers(short length) {

	vector<int> numbers;


	for (int i = 1; i <= length; i++) {

		short random = RandomNumber(1, 100);
		numbers.push_back(random);
	}

	return numbers;
}

vector<int> FillArrayWith1toN(short length) {

	vector<int> numbers;


	for (int i = 1; i <= length; i++) {
		numbers.push_back(i);
	}

	return numbers;
}


void PrintArray(vector<int> array, string message) {

	if (array.size() == 0) {
		message += " Empty";
	}

	cout << message;


	for (int i = 0; i < array.size(); i++) {

		cout << array[i] << "\t";


	}
	cout << endl;



}

int SumOfArray(vector<int> array) {
	int sum = 0;
	for (int i = 0; i < array.size(); i++) {
		sum += array[i];
	}
	return sum;
}


void Swap(int& a, int& b) {

	int temp = a;

	a = b;

	b = temp;

}
void ShuffleArray(vector<int>& array) {


	for (int i = 0; i < array.size(); i++) {
		int randomItem1 = RandomNumber(0, array.size() - 1);

		int randomItem2 = RandomNumber(0, array.size() - 1);

		Swap(array[randomItem1], array[randomItem2]);
	}

}

int main()
{
	srand((unsigned)time(NULL));

	short lengthOfArray = ReadPositiveNumber("Enter How Many Elements You Want");

	vector<int> array = FillArrayWith1toN(lengthOfArray);



	PrintArray(array, "Array Before Shuffle: \t");
	ShuffleArray(array);
	PrintArray(array, "Array After Shuffle: \t");


	return 0;
}