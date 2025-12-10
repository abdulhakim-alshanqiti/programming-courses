#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

using namespace std;

#include "../../libs/MyLib.h"
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;


void PrintYearCalendar(short Year) {
	printf("\n\n  _________________________________ \n\n");
	printf("\t   Calendar - %d ",Year);
	printf("\n\n  _________________________________ \n\n");

	for (int i = 1; i <= 12; i++) 
		PrintMonthCalendar(i, Year);

	
}


int main() {
	short Year = ReadNumber("Enter A Year");
	
	PrintYearCalendar(Year);


	return 0;
}