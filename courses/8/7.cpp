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




string DayLongName(short Day) {
	string arrDaysOfWeek[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	return arrDaysOfWeek[Day];

}


short DayOfWeekOrder(short Year,short Month,short Day) {
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;;
}

int main() {
	short Year = ReadNumber("Enter A Year");
	short Month = ReadNumber("Enter A Month");
	short Day = ReadNumber("Enter A Day");
	Printl("The Day You Choosed is " + to_string(Year) + "/"+ to_string(Month) + "/" + to_string(Day) );
	Printl("Its a " + DayLongName(DayOfWeekOrder(Year, Month, Day)));

	return 0;
}