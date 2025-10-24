//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <vector>
//using namespace std;
//
//
//int RandomNumber(int from, int to) {
//	return rand() % (to - from + 1) + from;
//}
//
//int ReadPositiveNumber(string message) {
//	int number = 0;
//	do {
//		cout << message << endl;
//
//		cin >> number;
//	} while (number <= 0);
//
//
//	return number;
//
//}
//
//
//
//
//void PrintArray(vector<int> array, string message) {
//
//	if (array.size() == 0) {
//		message += " Empty";
//	}
//
//	cout << message;
//
//
//	for (int i = 0; i < array.size(); i++) {
//
//		cout << array[i] << "\t";
//
//
//	}
//	cout << "\n\n";
//
//
//
//}
//
//
//void AddArrayElement(vector<int>& array, int number) {
//
//	array.push_back(number);
//}
//vector<int> ReadArrayElements() {
//	vector<int> array;
//	bool AddMoreNumbers = false;
//
//	do {
//
//		AddArrayElement(array, ReadPositiveNumber("Enter A Number"));
//		cout << "Do you want to add another number ?" << endl;
//		cin >> AddMoreNumbers;
//
//	} while (AddMoreNumbers);
//
//	return array;
//}
//vector<int> CopyArray(vector<int> array) {
//	vector<int> copy;
//	for (int i = 0; i < array.size(); i++) {
//
//
//		AddArrayElement(copy, array[i]);
//	}
//
//	return copy;
//
//}
//vector<int> FillArrayWithRandomNumbers(short length) {
//
//	vector<int> numbers;
//
//
//	for (int i = 1; i <= length; i++) {
//
//		short random = RandomNumber(1, 100);
//		numbers.push_back(random);
//	}
//
//	return numbers;
//}
//enum enPrimeNotPrime {
//	Prime = 1, NotPrime = 0
//};
//
//
//enPrimeNotPrime CheckPrime(int number) {
//	int M = number / 2;
//
//	for (int i = 2; i <= M; i++) {
//		if (number % i == 0)
//			return enPrimeNotPrime::NotPrime;
//
//	}
//	return enPrimeNotPrime::Prime;
//}
//vector<int> CopyOnlyPrimeNumbers(vector<int> array) {
//	vector<int> copy;
//
//	for (int i = 0; i < array.size(); i++) {
//		if (CheckPrime(array[i])) {
//			AddArrayElement(copy, array[i]);
//		}
//	}
//
//	return copy;
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	int number = ReadPositiveNumber("Enter How Many Elements");
//	vector<int> array = FillArrayWithRandomNumbers(number);
//
//	PrintArray(array, "Array 1 Elements: \n");
//	vector<int> array2 = CopyOnlyPrimeNumbers(array);
//	PrintArray(array2, "Array 2 Elements: \n");
//
//
//	return 0;
//}