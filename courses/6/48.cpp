//#include<iostream>
//#include<string>
//#include<vector>
//#include<fstream>
//#include"../../Libs/NumbersLib.h"
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
//
//void VectorToFile(vector<string>& vFileContent, string filePath) {
//	fstream MyFile;
//
//	MyFile.open(filePath, ios::out);
//
//
//
//	if (MyFile.is_open()) {
//		for (string& line : vFileContent) {
//
//			if (line != "")
//			{
//				MyFile << line << endl;
//			}
//		}
//	}
//	MyFile.close();
//}
//
//void PrintFileContent(string FilePath) {
//	vector <string> vFileContent = FileContentToVector(FilePath);
//
//	for (string& line : vFileContent) {
//		Printl(line);
//	}
//}
//void UpdateRecordFromFile(string FilePath, string Record, string UpdateTo) {
//	vector <string> vFileContent = FileContentToVector(FilePath);
//
//	for (string& line : vFileContent) {
//		if (line == Record) {
//			line = UpdateTo;
//		}
//	}
//
//	VectorToFile(vFileContent, FilePath);
//}
//int main() {
//
//	Printl("File Content Before Deletion");
//	PrintFileContent("./courses/6/files/48.txt");
//
//
//	UpdateRecordFromFile("./courses/6/files/48.txt", "Ali", "Omar");
//	Printl("File Content After Deletion");
//	PrintFileContent("./courses/6/files/48.txt");
//
//	return 0;
//}
//
//
