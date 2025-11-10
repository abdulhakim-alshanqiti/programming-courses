//#include <iostream>
//#include<string>
//#include "../../Libs/MyLib.h"
//using namespace Input;
//using namespace Strings;
//using namespace std;
//
//// My Solution
////enum enVowels {
////	A = 'A', E = 'E', I = 'I', O = 'O', U = 'U',
////};
////
////
////bool IsVowel(char Letter) {
////	switch (toupper(Letter))
////	{
////	case A: return true;
////	case E: return true;
////	case I: return true;
////	case O: return true;
////	case U: return true;
////	default:
////		return false;
////	}
////}
//
//// abu hadhud solution
//bool IsVowel(char Char) {
//	Char = tolower(Char);
//	return ((Char == 'a') || (Char == 'e') || (Char == 'i') || (Char == 'o') || (Char == 'u'));
//}
//
//string BoolToString(bool Bool) {
//
//	return (Bool) ? "True" : "False";
//}
//
//int main() {
//
//	char Letter = ReadChar("Pick a Letter");
//	string result = BoolToString(IsVowel(Letter));
//
//	cout << "Is Letter '" << Letter << "' a Vowel ? " + result;
//
//
//	return 0;
//}