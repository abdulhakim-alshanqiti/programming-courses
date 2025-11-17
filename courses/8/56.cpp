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



int main() {
	stDate StartOfVecation = ReadDate(2022, 1, 1);

	printf("Start Of Vecation is %s %d/%d/%d   \n", GetDayShortName(StartOfVecation).c_str(), StartOfVecation.Day, StartOfVecation.Month, StartOfVecation.Year);

	return 0;
}