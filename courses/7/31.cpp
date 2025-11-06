//#include <iostream>
//#include<string>
//#include "../../Libs/NumbersLib.h"
//using namespace Input;
//using namespace Strings;
//using namespace std;
//
//// My Solution 
////short CountLetterFrequncy(string MyString, char Letter, bool MatchCase = true) {
////	short Counter = 0;
////	for (short i = 0; i < MyString.length(); i++) {
////
////		if (MyString[i] == Letter || (!MatchCase && InvertCase(MyString[i]) == Letter))
////			Counter++;
////	}
////	return Counter;
////}
//
//// Abu Hadhud Solution
//short  CountLetter(string S1, char Letter, bool MatchCase = true)
//{
//	short Counter = 0;
//	for (short i = 0; i < S1.length(); i++)
//	{
//		if (MatchCase)
//		{
//			if (S1[i] == Letter)
//				Counter++;
//		}
//		else
//		{
//			if (tolower(S1[i]) == tolower(Letter))
//				Counter++;
//		}
//	}
//	return Counter;
//}
//
//
//
//
//int main() {
//	string MyString = ReadWords("Write a Sentence");
//
//	char Letter = ReadChar("What Letter You Want To Search For ?");
//
//	printf("letter '%c' frequncy is : %d \n", Letter, CountLetter(MyString, Letter));
//
//	printf("letter '%c' or '%c' frequncy is : %d \n", Letter, InvertCase(Letter), CountLetter(MyString, Letter, false));
//
//
//}