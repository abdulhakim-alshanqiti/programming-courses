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

	int _ObjectNumber;
public:

	clsA(int ObjectNumber) {
		_ObjectNumber = ObjectNumber;
	}

	void Print() {
		Printl("This is The Object Number : " + to_string(_ObjectNumber));
	}

};


int main() {
	vector<clsA> vA;

	for (short i = 1; i <= 5; i++)
	{
		vA.push_back(clsA(i));
	}

	for (short i = 0; i < 5; i++)
	{
		vA[i].Print()  ;
	}

	return 0;

}