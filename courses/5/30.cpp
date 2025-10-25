//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <vector>
//using namespace std;
//
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
//int SumOfArray(vector<int> array) {
//	int sum = 0;
//	for (int i = 0; i < array.size(); i++) {
//		sum += array[i];
//	}
//	return sum;
//}
//
//
//
//vector<int> SumOfTwoArrays(vector<int> array, vector<int> array2) {
//	vector<int> sum;
//
//	for (int i = 0; i < array.size(); i++) {
//		sum.push_back(array[i] + array2[i]);
//	}
//
//	return sum;
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	short lengthOfArray = ReadPositiveNumber("Enter How Many Elements You Want");
//
//	vector<int> array = FillArrayWithRandomNumbers(lengthOfArray);
//
//	PrintArray(array, "Array 1 items : \t");
//
//	vector<int> array2 = FillArrayWithRandomNumbers(lengthOfArray);
//
//
//	PrintArray(array2, "Array 2 items : \t");
//
//
//	vector<int> array3 = SumOfTwoArrays(array, array2);
//	PrintArray(array3, "Array 1 + Array 2: \t");
//	return 0;
//}