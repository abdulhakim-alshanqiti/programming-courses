//#include <iostream>
//#include<iomanip>
//#include <string>
//#include <cmath>
//
//using namespace std;
//
//#include "../../Libs/MyLib.h"
//using namespace Input;
//using namespace Output;
//using namespace Strings;
//using namespace Time;
//
//
//
//short NumberOfDaysFromBeginningOfYear(short Year, short Month, short Day)
//{
//	short CountOfDays = 0;
//	for (short i = 1; i < Month; i++) {
//		CountOfDays += NumberOfDaysInMonth(i,Year);
//	}	
//	
//	
//	CountOfDays += Day;
//	return CountOfDays;
//}
//int main() {
//	short Year = ReadNumber("Enter A Year");
//	short Month = ReadNumber("Enter A Month");
//	short Day = ReadNumber("Enter A Day");
//	Printl(	NumberOfDaysFromBeginningOfYear(Year,Month,Day));
//
//
//	return 0;
//}