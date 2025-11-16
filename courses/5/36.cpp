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
		message += " Empty";
	}

	cout << message;

	cout << "Array Length: " << array.size() << endl;

	for (int i = 0; i < array.size(); i++) {

		cout << array[i] << "\t";


	}
	cout << endl;



}


void AddArrayElement(vector<int>& array, int number) {

	array.push_back(number);
}
vector<int> ReadArrayElements() {
	vector<int> array;
	bool AddMoreNumbers = false;

	do {

		AddArrayElement(array, ReadPositiveNumber("Enter A Number"));
		cout << "Do you want to add another number ?" << endl;
		cin >> AddMoreNumbers;

	} while (AddMoreNumbers);

	return array;
}
int main()
{
	srand((unsigned)time(NULL));


	vector<int> array = ReadArrayElements();

	PrintArray(array, "Array 1 Elements: \n");


	return 0;
}