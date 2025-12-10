#include <iostream>
#include<string>
#include<vector>
#include "../../libs/MyLib.h"
using namespace Input;
using namespace std;
using namespace Strings;




int main() {
	string sWords = ReadStringWS("Please Enter A Sentence");

	cout << sWords << endl;
	string sWords2 = FindAndReplace(sWords, "hey", "hi", false);


	cout << sWords2 << endl;


	return 0;
}