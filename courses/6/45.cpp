//#include<iostream>
//#include<string>
//#include<vector>
//#include<fstream>
//#include"../../Libs/MyLib.h"
//using namespace Output;
//using namespace std;
//
//vector <string> FileContentToVector(string filePath) {
//	string line = "";
//	vector <string> vFileContent;
//	fstream MyFile;
//	MyFile.open(filePath, ios::in);
//	if (MyFile.is_open()) {
//
//		while (getline(MyFile, line)) {
//			vFileContent.push_back(line);
//		}
//
//
//	}
//	MyFile.close();
//	return vFileContent;
//}
//int main() {
//
//	vector <string> vFileContent = FileContentToVector("./courses/6/files/45.txt");
//
//	for (string &line : vFileContent) {
//		Printl(line);
//	}
//
//
//	return 0;
//}
//
//
