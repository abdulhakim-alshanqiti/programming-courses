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



string FormatDate(stDate Date ,string DateFormat = "dd/mm/yyyy") {
	string FormattedDateString = "";
	FormattedDateString = FindAndReplace(DateFormat, "dd", to_string(Date.Day));
	FormattedDateString = FindAndReplace(FormattedDateString, "mm", to_string(Date.Month));
	FormattedDateString = FindAndReplace(FormattedDateString, "yyyy", to_string(Date.Year));

	return FormattedDateString;

}
int main() {

	stDate Date2 = ReadDate(18, 11, 2003);
	
	Printl(FormatDate(Date2, "dd/mm/yyyy"));
	Printl(FormatDate(Date2, "mm/dd/yyyy"));
	Printl(FormatDate(Date2, "yyyy-mm-dd"));
	Printl(FormatDate(Date2, "Day : dd \nMonth : mm \nYear : yyyy"));

	return 0;
}