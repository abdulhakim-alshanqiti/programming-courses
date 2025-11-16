#include<iostream>
#include<string>
#include<fstream>
using namespace std; int main() {
	fstream MyFile;
	MyFile.open("./courses/6/files/42.txt", ios::out);// Open The File In Write Mode (Delete Past Content)

	if (MyFile.is_open()) {

		for (int i = 1; i <= 10; i++)
		{
			MyFile << "Hello Number: " << i << endl;

		}
	}
	MyFile.close();

	return 0;
}