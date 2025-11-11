#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace Vectors {
	vector<string> ReverseVector(vector<string>& Vector) {

		vector<string> ReversedVector;
		vector<string>::iterator iter = Vector.end();;


		while (iter != Vector.begin()) {
			iter--;
			ReversedVector.push_back(*iter);
		}
		return ReversedVector;
	}
}
namespace Strings {
	string RepeatString(int length, string StringToRepeat) {
		string Line;
		for (short i = 0; i < length; i++)
		{
			Line += StringToRepeat;
		}
		return Line;
	}
	string RemovePunctioationsFromString(string String) {
		string NewString = "";
		for (short i = 0; i < String.length(); i++)
		{
			if (!ispunct(String[i])) {
				NewString += String[i];
			}
		}
		return NewString;
	}


	vector<string> SplitString(string String, string Seperator) {
		short pos = 0;
		string sWord = "";

		short WordCount = 0;
		vector<string> vString;

		while ((pos = String.find(Seperator)) != std::string::npos)
		{
			sWord = String.substr(0, pos);

			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			String.erase(0, pos + Seperator.length());
		}

		if (String != "")
		{
			vString.push_back(String);

		}
		return vString;

	}
	string ReverseWords(string sWords, string Seperator) {
		string ReversedString;
		vector<string> vWords = SplitString(sWords, " ");
		vector<string>::iterator iter = vWords.end();;


		while (iter != vWords.begin()) {
			iter--;
			ReversedString += *iter + Seperator;
		}

		ReversedString = ReversedString.substr(0, ReversedString.length() - Seperator.length());
		return ReversedString;
	}
	string JoinString(vector<string>& vString, string Seperator) {
		string Result = "";
		for (string& String : vString) {
			Result += String + Seperator;
		}


		return Result.substr(0, Result.length() - Seperator.length());
	}
	string JoinString(string String[], short length, string Seperator) {
		string Result = "";
		for (short i = 0; i < length; i++)
		{
			Result += String[i] + Seperator;
		}


		return Result.substr(0, Result.length() - Seperator.length());
	}

	string TrimLeft(string S1) {

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	string TrimRight(string S1) {
		for (int i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}


	string Trim(string String) {
		return TrimLeft(TrimRight(String));
	}
	string BoolToString(bool Bool) {

		return (Bool) ? "True" : "False";
	}

	char InvertCase(char Char) {
		return  isupper(Char) ? tolower(Char) : toupper(Char);
	}

	string LowerAllLetters(string S1) {
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	string LowerFirstLetterOfEachWord(string S1) {
		bool isFirstLetter = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (isFirstLetter && S1[i] != ' ')
				S1[i] = tolower(S1[i]);


			isFirstLetter = (S1[i] == ' ' ? true : false);

		}
		return S1;
	}
	string UpperFirstLetterOfEachWord(string S1) {
		bool isFirstLetter = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (isFirstLetter && S1[i] != ' ')
				S1[i] = toupper(S1[i]);


			isFirstLetter = (S1[i] == ' ' ? true : false);

		}
		return S1;
	}
	string UpperAllLetters(string S1) {
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	string FindAndReplace(string String, string Find, string Replace, bool MatchCase = true) {
		vector<string> vWords = SplitString(String, " ");
		if (MatchCase) {

			for (string& Word : vWords) {
				if (Word == Find) {
					Word = Replace;
				}
			}

		}
		else {
			for (string& Word : vWords) {
				if (LowerAllLetters(Word) == LowerAllLetters(Find)) {
					Word = Replace;
				}
			}
		}

		return JoinString(vWords, " ");

	}
}
namespace Input {
	void SeedRandomness() {
		srand((unsigned)time(NULL));
	}
	int RandomNumber(int from, int to) {
		return rand() % (to - from + 1) + from;
	}

	string ReadStringWS(string message) {
		string input = "";

		cout << message << endl;
		getline(cin >> ws, input);

		return input;
	}
	string ReadString(string message) {
		string input = "";

		cout << message << endl;
		getline(cin, input);

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
		} while (number < 0);
		return number;
	}
	float ReadPositiveFloat(string message) {
		float number = 0.0;
		do {
			number = ReadNumber(message);
		} while (number < 0);
		return number;
	}
	double ReadPositiveDouble(string message) {
		double number = 0.0;
		do {
			number = ReadNumber(message);
		} while (number < 0);
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

	void Print(long long message) {
		cout << message;
	}
	void Printl(long long message) {
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
