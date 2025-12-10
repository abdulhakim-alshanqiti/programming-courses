#include <iostream>
#include<string>
#include<vector>
#include "../../libs/MyLib.h"
using namespace Input;
using namespace std;
using namespace Strings;


int main() {
	string sWords = ReadStringWS("Please Enter A Sentence");

	cout << RemovePunctioationsFromString(sWords) << endl;


	return 0;
}