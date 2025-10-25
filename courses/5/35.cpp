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
//
//
//
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
//	cout << endl;
//
//
//
//}
//
//
//int SearchForNumberInArray(vector<int> array, short number) {
//
//
//	for (int i = 0; i < array.size(); i++) {
//
//		if (array[i] == number) {
//
//			return i;
//		}
//
//	}
//
//	return -1;
//
//
//
//
//
//
//}
//
//void PrintResultOfSearch(int number, int index) {
//	if (index == -1) {
//		cout << "the Number You are looking for is :" +
//			to_string(number) << "\nI couldn't find it " << endl;
//	}
//	else {
//		cout << "the Number You are looking for is :" + to_string(number) << "\nis at position: " + to_string(index) + "\nand its order is " + to_string(index + 1) << endl;
//	}
//}
//
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	short lengthOfArray = ReadPositiveNumber("Enter How Many Elements You Want");
//
//	vector<int> array = FillArrayWithRandomNumbers(lengthOfArray);
//
//	PrintArray(array, "Array 1 Elements: \n");
//
//	short numberToSearch = ReadPositiveNumber("Enter the Number You Want to Search For");
//
//
//	int number_Index = SearchForNumberInArray(array, numberToSearch);
//
//	PrintResultOfSearch(numberToSearch, number_Index);
//
//	return 0;
//}