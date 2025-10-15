//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <vector>
//using namespace std;
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
//void PrintArray(vector<int> array) {
//	cout << "original array : ";
//
//
//	for (int i = 0; i < array.size(); i++) {
//
//		cout << array[i] << " ";
//
//
//	}
//	cout << endl;
//}
//
//int main()
//{
//
//	srand((unsigned)time(NULL));
//	short lengthOfArray = ReadPositiveNumber("Enter How Many Elements You Want");
//
//	vector<int> array = FillArrayWithRandomNumbers(lengthOfArray);
//
//	PrintArray(array);
//
//	return 0;
//}