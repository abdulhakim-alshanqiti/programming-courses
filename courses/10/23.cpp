#include <iostream>
#include "../../libs/MyLib.h"
#include "../../libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsA {
private:
	short _Var1 = 10;

protected:
	short _Var2 = 20;

public:
	short Var3 = 30;


	friend int SumA(clsA ObjectA); // without this it won't compile
};

//void SumANotFriend(clsA objectA) {
//	Printl(objectA._Var1);
//	Printl(objectA._Var2);
//	Printl(objectA.Var3);
//}

int SumA(clsA ObjectA) {
	return	ObjectA._Var1 + ObjectA._Var2 + ObjectA.Var3;
}




int main() {
	clsA ObjectA;

	Print("The Sum is ");
	Printl( SumA(ObjectA));


	return 0;

}