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
//void DeleteRecordFromFile(string FilePath, string Record) {
//	vector <string> vFileContent = FileContentToVector(FilePath);
//
//	for (string& line : vFileContent) {
//		if (line == Record) {
//			line = "";
//		}
//	}
//
//	VectorToFile(vFileContent, FilePath);
//}
//int main() {
//
//	Printl("File Content Before Deletion");
//	PrintFileContent("./courses/6/files/46.txt");
//
//
//	DeleteRecordFromFile("./courses/6/files/46.txt", "nah");
//	Printl("File Content After Deletion");
//	PrintFileContent("./courses/6/files/46.txt");
//
//	return 0;
//}
//
//
