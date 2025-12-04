#include <iostream>
#include<iomanip>
#include "../../Libs/MyLib.h"
#include "../../Libs/clsDate.h"
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace std;


int main() {
	clsDate Date;
	Date.Print();

	clsDate Date2(1,1,2025);
	Date2.Print();

	clsDate Date3("18/11/2003");
	Date3.Print();

	clsDate Date4(250,2003);
	Date4.Print();

	return 0;
}