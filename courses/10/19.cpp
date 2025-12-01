#include <iostream>
#include "../../Libs/MyLib.h"
#include "../../Libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsA {
private:
	string _Name = "Name";


public:

	string Name() {
		return _Name;
	}


};

class clsB : protected clsA {


};

class clsC : public clsB {

public:
	void PrintName() {
		Printl(Name()); // C++ function Name() is inaccessible if class B inherts A privatly private
	}

};


int main() {
	clsC C;

	C.PrintName();
	


	return 0;

}