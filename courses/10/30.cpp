#include <iostream>
#include <vector>
#include "../../libs/MyLib.h"
#include "../../libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsA {

	int _ObjectNumber =0;
public:

	clsA(int ObjectNumber) {
		_ObjectNumber = ObjectNumber;
	}
	clsA() {

	}
	void Print() {
		Printl("This is The Object Number : " + to_string(_ObjectNumber));
	}

};


int main() {
	int NumberOfObjects = ReadNumber("Enter How Many Objects");
	clsA * ObjectArr = new clsA[NumberOfObjects];


	for (short i = 0; i < NumberOfObjects; i++)
	{
		ObjectArr[i] = (clsA(i+1));
	}

	for (short i = 0; i < NumberOfObjects; i++)
	{
		ObjectArr[i].Print();
	}

	delete[] ObjectArr;
	return 0;

}