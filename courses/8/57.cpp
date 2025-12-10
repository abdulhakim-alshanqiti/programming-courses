#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

#include "../../libs/MyLib.h"
#include "../../libs/Date.h"
#include <cstdio>

using namespace std;
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;

//enum enDateCompare { Before=-1 ,Equal, After };
//string DateCompareToString(enDateCompare Compare) {
//	switch (Compare) {
//
//	case Before: return "Before";
//	case Equal: return "Equal";
//	case After: return "After";
//
//	}
//
//}
//enDateCompare CompareDates(stDate Date1, stDate Date2) {
//	if (IsDate1BeforeDate2(Date1, Date2))
//		return Before;
//	if (IsDate1AfterDate2(Date1,Date2))
//		return After;
//	else 
//		return Equal;
//}
//

int main() {
	stDate Date1 = ReadDate(2021, 1, 1);
	stDate Date2 = ReadDate(2022, 1, 1);


	printf("Date1 is %s %d/%d/%d   \n", GetDayShortName(Date1).c_str(), Date1.Day, Date1.Month, Date1.Year);

	printf("Date2 is %s %d/%d/%d   \n", GetDayShortName(Date2).c_str(), Date2.Day, Date2.Month, Date2.Year);

	printf("Compare Date1 & Date2 \nDate1 Is %s Date2  \n",DateCompareToString( CompareDates(Date1, Date2) ).c_str()   );


	return 0;
}