#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

using namespace std;

#include "../../Libs/MyLib.h"
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;



int main() {
/*	short Year = ReadNumber("Enter A Year");
	short Month = ReadNumber("Enter A Month");
	short Day = ReadNumber("Enter A Day");*/

	short DayCount = NumberOfDaysFromBeginningOfYear(2003, 11, 18);
	Printl( "Number Of Days Since The Beginning" + DayCount);




	return 0;
}