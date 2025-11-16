#include <iostream>
#include<string>
#include "../../Libs/MyLib.h"
using namespace Input;
using namespace Strings;
using namespace std;




short CountWords(string String) {
	short pos = 0;
	string sWord = "";
	string dilim = " ";
	short WordCount = 0;

	while ((pos = String.find(dilim)) != std::string::npos)
	{
		sWord = String.substr(0, pos);

		if (sWord != "")
		{
			WordCount++;
		}

		String.erase(0, pos + dilim.length());
	}

	if (String != "")
	{
		WordCount++;

	}
	return WordCount;

}


int main() {

	string String = ReadStringWS("Pick a String");
	short Count = CountWords(String);
	cout << "The Count Of The Words Is " << Count;
	return 0;
}