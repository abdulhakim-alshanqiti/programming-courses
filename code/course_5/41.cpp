//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <vector>
//using namespace std;
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
//
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
//bool IsNumberInArray(vector<int> array, short number) {
//
//	for (int i = 0; i < array.size(); i++) {
//
//		if (array[i] == number) {
//
//			return true;
//		}
//
//	}
//
//	return false;
//}
//bool CheckIfArrayIsPalindrome(vector<int> array) {
//
//
//	for (int i = 0; i < array.size(); i++) {
//
//
//		if (array[i] != array[(array.size() - 1) - i]) {
//			return false;
//
//
//		}
//
//
//	}return true;
//}
//int main()
//{
//	vector<int> array = { 1,3,3,2,1 };
//
//	PrintArray(array, "Array 1 Elements: \n");
//	bool isPalindrome = CheckIfArrayIsPalindrome(array);
//
//	if (isPalindrome) {
//		cout << "the array is Palindrome" << endl;
//	}
//	else {
//		cout << "the array is not Palindrome" << endl;
//	}
//
//
//	return 0;
//}