
#include<iostream>
#include<vector>
#include"../../Libs/MyLib.h"  

using namespace std;
using namespace Output;



int main() {
	vector <int> vNumbers = { 1,2,3,4,5 };

	// copies data of the item to a variable called number
	// this is slower
	for (int number : vNumbers) {
		Printl(number);
	}

	// gets the value by refrence without copying it
	// this is faster
	for (int& number : vNumbers) {
		Printl(number);
	}

	return 0;
}