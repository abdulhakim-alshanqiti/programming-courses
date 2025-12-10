#include <iostream>
#include "../../libs/MyLib.h"
#include "../../libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsA {


public:
	int x = 0;

	void Print() {
		Printl("The Value Of X = " + to_string(x));
	}

	void Func1(clsA ObjectA) {
		ObjectA.x = 200;
	}

	void Func2(clsA &ObjectA) {
		ObjectA.x = 10;
	}
};


int main() {
	clsA A;

	A.x = 50;
	A.Print();


	A.Func1(A);

	Printl("\nA After Update By Value");
	A.Print();

	A.Func2(A);
	Printl("\nA After Update By Ref ");
	A.Print();
	return 0;

}