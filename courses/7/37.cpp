#include <iostream>
#include<string>
#include<vector>
#include "../../Libs/MyLib.h"
using namespace Input;
using namespace Strings;
using namespace std;




vector<string> SplitString(string String, string Separator) {
	short pos = 0;
	string sWord = "";

	short WordCount = 0;
	vector<string> vString;

	while ((pos = String.find(Separator)) != std::string::npos)
	{
		sWord = String.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		String.erase(0, pos + Separator.length());
	}

	if (String != "")
	{
		vString.push_back(String);

	}
	return vString;

}


int main() {

	string String = ReadStringWS("Pick a String");
	vector<string> vString = SplitString(String, " ");
	cout << "The Tokens Are " << vString.size() << endl;;

	for (string& Word : vString) {
		cout << Word << endl;
	}


	return 0;
}