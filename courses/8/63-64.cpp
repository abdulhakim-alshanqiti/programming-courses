#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

#include "../../Libs/MyLib.h"
#include "../../Libs/Date.h"
#include <cstdio>

using namespace std;
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;


string DateToString(stDate Date) {
	return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

stDate DateFromString(string DateString) {
	vector<string> vDate = SplitString(DateString, "/");
	return 	stDate(stoi(vDate[0]), stoi(vDate[1]), stoi(vDate[2]));
}


stDate ReadDateString() {
	stDate Date;
	bool DateIsValid = false;
	do {
		string DateString =
			ReadStringWS("Please Enter A day In This Format dd/mm/yyyy ");

		Date = DateFromString(DateString);
		DateIsValid = IsDateValid(Date);
		if (!DateIsValid) {
			Printl("The Date You Entered Isn't Valid, Please Try Again");
		}

	} while (!DateIsValid);

	return Date;
}


int main() {

	stDate Date1 = ReadDate(18, 11, 2003);

	string DateString = DateToString(Date1);
	Printl("(Date 1) is " + DateString);

	stDate Date2 = ReadDateString();

	printf("( Date 2 ) \nDay: %d \nMonth: %d \nYear: %d   \n", Date2.Day, Date2.Month, Date2.Year);
	return 0;
}