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


//void PrintCalendar(short matrix[5][7],short Month) {
//
//	printf(" _____________________ %s _____________________ \n", MonthLongName(Month).c_str());
//	Printl(" Sun\tMon\tTue\tWed\tThu\tFri\tSat");
//	for (short i = 0; i < 5; i++) {
//		
//		for (short j = 0; j < 7; j++)
//		{
//			if (matrix[i][j] == 0)
//				cout << setw(3) <<  "\t";
//			 else
//				cout << setw(3) << matrix[i][j] << "\t";
//
//		}
//		Printl();
//	}
//	printf(" __________________________________________________ \n");
//
//}
//
//void PrintDaysOfMonth(short Month,short Year)
//{
//	const short rows = 5;
//	const short columns = 7;
//	short matrix[rows][columns] = {};
//
//	short NumberOfDays = NumberOfDaysInMonth(Month,Year);
//	short FirstDay = IndexOfDayInYear(Year,Month,1) ;
//	short counter = 0;
//	for (short i = 0; i < rows; i++) {
//		for (short j = (counter == 0) ? FirstDay : 0; 
//			(j < columns && counter != NumberOfDays);j++) {
//				counter++;
//				matrix[i][j] = counter;
//		}
//	};
//
//
//	PrintCalendar(matrix,Month);
//}

/// The Above Is My Solution



int main() {
	short Year = ReadNumber("Enter A Year");
	short Month = ReadNumber("Enter A Month");
	short Day = ReadNumber("Enter A Day");
	Printl("The Day You Choosed is " + to_string(Year) + "/" + to_string(Month) + "/" + to_string(Day));
	Printl("Its a " + DayLongName(IndexOfDayInYear(Year, Month, Day)));

	PrintDaysOfMonth( 10, 2030);

	return 0;
}