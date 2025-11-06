//#include <iostream>
//#include<string>
//#include<vector>
//#include "../../Libs/NumbersLib.h"
//using namespace Input;
//
//using namespace std;
//using namespace Strings;
//
//
//string FindAndReplace(string String, string Find, string Replace) {
//
//	short pos = String.find(Find);
//	while (pos != std::string::npos) {
//		String.erase(pos, Find.length());
//		String.insert(pos, Replace);
//
//		pos = String.find(Find);
//	}
//
//
//	return String;
//}
//
//string FindAndReplaceUsingBuiltIn(string String, string Find, string Replace) {
//
//	short pos = String.find(Find);
//	while (pos != std::string::npos) {
//		String = String.replace(pos, Find.length(), Replace);
//		pos = String.find(Find);
//	}
//
//
//	return String;
//}
//int main() {
//	string sWords = ReadWords("Please Enter A Sentence");
//
//	cout << sWords << endl;
//	string sWords2 = FindAndReplace(sWords, "hey", "hi");
//
//
//	cout << sWords2 << endl;
//
//
//	return 0;
//}