#pragma once
#include <iostream>


using namespace std;
namespace NumbersLib {
	void SeedRandomness() {
		srand((unsigned)time(NULL));
	}
	int RandomNumber(int from, int to) {
		return rand() % (to - from + 1) + from;
	}
	string ReadString(string message) {
		string input = "";

		cout << message << endl;
		cin >> input;

		return input;
	}
	char ReadChar(string message) {
		char input = ' ';

		cout << message << endl;

		cin >> input;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "This is an Invalid Letter Please Enter A Valid Letter !" << endl;

			cout << message << endl;
			cin >> input;
		}

		return input;
	}

	int ReadNumber(string message) {
		int number = 0;

		cout << message << endl;
		cin >> number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "This is an Invalid Number Please Enter A Valid Number!" << endl;

			cout << message << endl;
			cin >> number;
		}

		return number;
	}
	int ReadPositiveNumber(string message) {
		int number = 0;
		do {
			number = ReadNumber(message);
		} while (number >= 0);
		return number;
	}
	int ReadNumberInRange(string message, int from, int to) {
		int number = 0;
		do {
			number = ReadNumber(message);
		} while (number < from || number > to);
		return number;
	}


}


namespace Output {

	void Printl() {
		cout << endl;
	}


	void Print(string message) {
		cout << message;
	}
	void Printl(string message) {
		cout << message << endl;
	}
	void Print(char message) {
		cout << message;
	}
	void Printl(char message) {
		cout << message << endl;
	}

	void Print(int message) {
		cout << message;
	}
	void Printl(int message) {
		cout << message << endl;
	}
	void Print(double message) {
		cout << message;
	}
	void Printl(double message) {
		cout << message << endl;
	}
	void Print(float message) {
		cout << message;
	}
	void Printl(float message) {
		cout << message << endl;
	}
}
