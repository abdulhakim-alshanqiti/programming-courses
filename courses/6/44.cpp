#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"../../Libs/MyLib.h"
using namespace Output;
using namespace std;

void PrintFileContent(string filePath) {
	string line = "";
	fstream MyFile;
	MyFile.open(filePath, ios::in);
	if (MyFile.is_open()) {

		while (getline(MyFile, line)) {
			Printl(line);
		}


	}
	MyFile.close();
}
int main() {

	PrintFileContent("./courses/6/files/44.txt");


	return 0;
}


