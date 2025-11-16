
#include<iostream>
#include<vector>
#include"../../Libs/MyLib.h"  

using namespace std;
using namespace Output;



int main() {
	vector <int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);


	for (int& number : vNumbers) {
		Printl(number);
	}

	return 0;
}