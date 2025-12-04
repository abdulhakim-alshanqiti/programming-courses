#include <iostream>
#include <vector>
#include "../../Libs/MyLib.h"
#include "../../Libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsA {

	int _ObjectNumber = 0;
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
	clsA ObjectArr[3] = {clsA(10),clsA(20),clsA(30)};


	for (short i = 0; i < 3; i++)
	{
		ObjectArr[i] = (clsA(i + 1));
	}

	for (short i = 0; i < 3; i++)
	{
		ObjectArr[i].Print();
	}

	return 0;

}