#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include "../../../libs/MyLib.h"
using namespace Input;
using namespace std;
using namespace Strings;
using namespace Output;


vector<string> GetStringsFromFile() {
	string ClientsFilePath = "./courses/7/Projects/extra.txt";
	vector<string> vStrings;

	fstream MyFile;

	string line = "";

	MyFile.open(ClientsFilePath, ios::in);

	if (MyFile.is_open()) {
		while (getline(MyFile, line)) {

			vStrings.push_back(line);
		}
	}

	MyFile.close();

	return vStrings;
}
void SaveClientsDataToNewFile(vector<string>& vStrings, bool isA) {
	fstream MyFile;
	string Line = "";
	
	string ClientsFilePath = (isA) ?  "./courses/7/Projects/a.txt" : "./courses/7/Projects/b.txt";
	MyFile.open(ClientsFilePath, ios::out);


	if (isA) {
		if (MyFile.is_open()) {
			for (string& Line : vStrings) {
				if (Line.find("A") != std::string::npos)
					MyFile << Line << endl;

			}
		}
	}
	else {


		if (MyFile.is_open()) {
			for (string& Line : vStrings) {
				if (Line.find("A") == std::string::npos)
					MyFile << Line << endl;

			}
		}
	}



	MyFile.close();
}

int main() {

	vector<string> vStrings =	GetStringsFromFile();

	SaveClientsDataToNewFile(vStrings, true);
	SaveClientsDataToNewFile(vStrings, false);


	return 0;
}