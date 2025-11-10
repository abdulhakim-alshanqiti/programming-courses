//#include <iostream>
//#include<string>
//#include "../../Libs/MyLib.h"
//using namespace Input;
//using namespace Strings;
//using namespace std;
//
//
//// My Solution
//// 
////void PrintLetters(string String) {
////	printf("Words in String:\n");
////	string Word = "";
////
////	for (short i = 0; i < String.length(); i++)
////	{
////		bool IsWord = (String[i] != ' ' ? true : false);
////
////		if (IsWord)
////			Word += String[i];
////
////		else if (Word.length() > 0)
////		{
////			cout << Word << endl;
////			Word = "";
////		}
////
////	}
////	if (Word.length() > 0)
////	{
////		cout << Word << endl;
////	}
////}
//
//// Abu hadhud solution
//
//
//
//void PrintLetters(string String) {
//	printf("Words in String:\n");
//	string Seperator = " ";
//	string Word = "";
//	short pos = 0;
//
//
//	while ((pos = String.find(Seperator)) != std::string::npos)
//	{
//		Word = String.substr(0, pos);
//
//		if (Word != "")
//			cout << Word << endl;
//
//		String.erase(0, pos + Seperator.length());
//
//	}
//	if (String != "")
//	{
//		cout << String << endl;
//	}
//}
//int main() {
//
//	string String = ReadStringWS("Pick a String");
//
//	PrintLetters(String);
//	return 0;
//}