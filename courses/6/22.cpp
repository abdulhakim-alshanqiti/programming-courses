
#include<iostream>
#include<vector>
#include<string>
#include"../../libs/MyLib.h"  

using namespace std;
using namespace Output;



int main() {
	vector <int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);

	Printl("Vector Stack Size: " + to_string(vNumbers.size()));

	while (!vNumbers.empty()) {
		vNumbers.pop_back();
	}
	//vNumbers.clear();
	Printl("Vector Stack Is Empty Its Size is : " + to_string(vNumbers.size()));


	for (int& number : vNumbers) {
		Printl(number);
	}

	return 0;
}