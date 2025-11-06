#include <iostream>
#include<string>
#include<vector>
#include "../../Libs/NumbersLib.h"
using namespace Input;
using namespace std;
using namespace Strings;
// my solution
//string InvertWord(string Word) {
//	string InvertedWord = "";
//	for (short i = 0; i < Word.length(); i++) {
//		InvertedWord += InvertCase(Word[i]);
//
//	}
//	return InvertedWord;
//}
//
//
//string FindAndReplace(string String, string Find, string Replace, bool MatchCase = true) {
//	short pos = String.find(Find);
//	while (pos != std::string::npos) {
//		String.erase(pos, Find.length());
//		String.insert(pos, Replace);
//
//		pos = String.find(Find);
//	}
//
//	if (!MatchCase) {
//		Find.front() = InvertCase(Find.front());
//
//		pos = String.find(Find);
//		while (pos != std::string::npos) {
//			String.erase(pos, Find.length());
//			String.insert(pos, Replace);
//
//			pos = String.find(Find);
//		}
//	}
//	return String;
//}
// 

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

int main() {
	string sWords = ReadWords("Please Enter A Sentence");

	cout << sWords << endl;
	string sWords2 = FindAndReplace(sWords, "hey", "hi", false);


	cout << sWords2 << endl;


	return 0;
}