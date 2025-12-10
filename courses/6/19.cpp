
#include<iostream>
#include<vector>
#include"../../libs/MyLib.h"  

using namespace std;
using namespace Output;
using namespace Input;


void PrintVector(vector <int>& vNumbers) {
	Printl("Vector Items :");
	for (int& number : vNumbers) {
		Printl(number);
	}

}

void ReadNumbers(vector <int>& vector) {
	char ReadMore = 'Y';

	while (ReadMore == 'Y' || ReadMore == 'y') {
		system("cls");

		int number = ReadNumber("What Number Do You Want to Add?");

		vector.push_back(number);


		Printl("Do You Want To Add More Numbers?");
		cin >> ReadMore;

	};
}


int main() {
	vector <int> vNumbers;
 
	ReadNumbers(vNumbers);
	PrintVector(vNumbers);

	return 0;
}