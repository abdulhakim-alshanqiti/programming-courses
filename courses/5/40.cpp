#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;


void PrintArray(vector<int> array, string message) {

	if (array.size() == 0) {
		message += " Empty";
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

vector<int> CopyArray(vector<int> array) {
	vector<int> copy;
	for (int i = 0; i < array.size(); i++) {


		AddArrayElement(copy, array[i]);
	}

	return copy;

}
bool IsNumberInArray(vector<int> array, short number) {

	for (int i = 0; i < array.size(); i++) {

		if (array[i] == number) {

			return true;
		}

	}

	return false;
}
vector<int> CopyOnlyDistinctNumbers(vector<int> array) {
	vector<int> copy;

	for (int i = 0; i < array.size(); i++) {
		int number = array[i];


		if (!IsNumberInArray(copy, number)) {
			AddArrayElement(copy, number);
		}


	}

	return copy;
}

int main()
{
	vector<int> array = { 1,1,2,3,2,5,3 };

	PrintArray(array, "Array 1 Elements: \n");
	vector<int> array2 = CopyOnlyDistinctNumbers(array);
	PrintArray(array2, "Array 2 Elements: \n");


	return 0;
}