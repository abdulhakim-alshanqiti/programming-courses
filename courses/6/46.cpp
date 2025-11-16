#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"../../Libs/MyLib.h"
using namespace Output;
using namespace std;

vector <string> FileContentToVector(string filePath) {
	string line = "";
	vector <string> vFileContent;
	fstream MyFile;
	MyFile.open(filePath, ios::in);
	if (MyFile.is_open()) {

		while (getline(MyFile, line)) {
			vFileContent.push_back(line);
		}


	}
	MyFile.close();
	return vFileContent;
}

void VectorToFile(vector<string>& vFileContent, string filePath) {
	fstream MyFile;

	MyFile.open(filePath, ios::out);



	if (MyFile.is_open()) {
		for (string& line : vFileContent) {

			if (line != "")
			{
				MyFile << line << endl;
			}
		}
	}
	MyFile.close();
}
int main() {

	vector <string> vFileContent = FileContentToVector("./courses/6/files/46.txt");

	VectorToFile(vFileContent, "./courses/6/files/46.txt");


	return 0;
}


