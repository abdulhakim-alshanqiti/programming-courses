//#include <iostream>
//#include <string>
//using namespace std;
//
//
//
//int ReadPositiveNumber(string message) {
//	int n = 0;
//	do {
//		cout << message << endl;
//
//		cin >> n;
//	} while (n <= 0);
//
//	return n;
//}
//bool IsPerfectNumber(int number) {
//	int M = number / 2; // no number can be divided by more than its half
//	int sum = 0;
//
//
//	for (int i = 1; i <= M; i++) {
//		if (number % i == 0)
//
//			sum += i;
//
//	}
//	cout << "the sum is " << sum << endl;
//	return (sum == number);
//
//}
//
//
//
//void PrintIsPerfectNumber(int number) {
//
//
//	if (IsPerfectNumber(number))
//		cout << "the number " << number << " is a perfect number" << endl;
//
//	else
//		cout << "the number " << number << " is not a perfect number" << endl;
//
//
//
//
//}
//int main()
//{
//	int number = ReadPositiveNumber("Please Enter a Number!");
//
//	PrintIsPerfectNumber(number);
//	return 0;
//
//}
//
