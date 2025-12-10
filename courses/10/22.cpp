#include <iostream>
#include "../../libs/MyLib.h"
#include "../../libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsA{
private:
	string _Var1 = "Private Variable";

protected:
	string _Var2 = "Protected Variable";

public:
	string Var3 = "Public Variable";


	friend class clsB; // without this it won't compile
};

class clsB{
public:
	void PrintA(clsA objectA) {
		Printl(objectA._Var1);
		Printl(objectA._Var2);
		Printl(objectA.Var3);
	}
};



int main() {
	clsA ObjectA;
	clsB ObjectB;

	ObjectB.PrintA(ObjectA);


	return 0;

}