#include <iostream>
#include<string>
#include<vector>
#include "../../Libs/MyLib.h"
using namespace Input;
using namespace Strings;
using namespace std;

int main() {
	string sWords = ReadStringWS("Please Enter A Sentence");

	cout << ReverseWords(sWords, " ") << endl;


	return 0;
}