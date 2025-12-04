#pragma once
#include "Date.h"
	struct stDate {
		short Day = 0;
		short Month = 0;
		short Year = 0;
	};

	struct stPeriod {
		stDate Start = { 0,0,0 };
		stDate End = { 0,0,0 };
	};
	enum enDateCompare { Before = -1, Equal, After };
class clsDate {

private:


	stDate _Date;
public:

	clsDate() {
		_Date =GetSystemDate();
	}
	clsDate(short Day,short Month,short Year) {
		_Date = {Day,Month,Year};
	}
	clsDate(string DateString) {
		_Date = DateFromString(DateString);
	}
	clsDate(short DaysToAdd, short Year) {
		_Date=  IncreaseDateByXDays(stDate({ 1,1,Year }), DaysToAdd);
		
	}
	static void Print(stDate Date) {
		printf("%d/%d/%d\n",Date.Day,Date.Month,Date.Year);
	}
	void Print() {
		printf("%d/%d/%d\n", _Date.Day, _Date.Month, _Date.Year);
	}

 static	stDate GetSystemDate() {
		stDate Date;
		time_t t = time(0);
		// get time now 
		tm* now = localtime(&t);
		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;
	}



static string DateToString(stDate Date) {
	return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

static stDate DateFromString(string DateString) {
	vector<string> vDate = SplitString(DateString, "/");
	return 	stDate(stoi(vDate[0]), stoi(vDate[1]), stoi(vDate[2]));
}


static string DayLongName(short Day) {
	string arrDaysOfWeek[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	return arrDaysOfWeek[Day];

}
static string DayShortName(short Day) {
	string arrDaysOfWeek[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDaysOfWeek[Day];

}

static string MonthLongName(short Month) {
	string arrOfMonth[13] = { "", "January","February","March","April","May","June","July","August","September","October","November","December" };
	return arrOfMonth[Month];
}
static string MonthShortName(short Month) {
	string arrOfMonth[13] = { "", "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	return arrOfMonth[Month];
}


static short DayOfWeekOrder(short Year, short Month, short Day) {
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
static short DayOfWeekOrder(stDate Date) {
	return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
}



static bool IsLeapYear(short year) {
	return   (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}
static short NumberOfDaysInMonth(short Month, short Year) {
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDaysInEachMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	return	(Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDaysInEachMonth[Month];
}
static short NumberOfDaysInMonth(stDate Date) {
	return NumberOfDaysInMonth(Date.Month, Date.Year);
}
static short NumberOfDaysInYear(short Year) {
	return  (IsLeapYear(Year) ? 366 : 365);
}
static short NumberOfDaysInYear(stDate Date) {
	return NumberOfDaysInYear(Date.Year);
}


static short NumberOfHoursInMonth(short Month, short Year) {
	return NumberOfDaysInMonth(Month, Year) * 24;
}
static int NumberOfMinutesInMonth(short Month, short Year) {
	return NumberOfHoursInMonth(Month, Year) * 60;
}
static int NumberOfSecondsInMonth(short Month, short Year) {
	return NumberOfMinutesInMonth(Month, Year) * 60;
}
static short NumberOfHoursInYear(short Year) {
	return NumberOfDaysInYear(Year) * 24;
}
static int NumberOfMinutesInYear(short Year) {
	return NumberOfHoursInYear(Year) * 60;
}
static int NumberOfSecondsInYear(short Year) {
	return NumberOfMinutesInYear(Year) * 60;
}

static bool IsDateValid(stDate Date) {
	return
		(Date.Year > 0
			&& (13 > Date.Month > 0)
			&& NumberOfDaysInMonth(Date) >= Date.Day > 0);
}

static stDate ReadDate(short Day = 0, short Month = 0, short Year = 0) {
	stDate Date;

	while (!IsDateValid(Date)) {
		Date.Year = (Year == 0) ? ReadPositiveNumber("Enter A Year") : Year;
		Date.Month = (Month == 0) ? ReadPositiveNumber("Enter A Month") : Month;
		Date.Day = (Day == 0) ? ReadPositiveNumber("Enter A Day") : Day;
		if (!IsDateValid(Date))
			Printl("Please Enter A Valid Date");
	}
	return Date;
}

static stDate ReadDate(stDate Date) {
	return ReadDate(Date.Year, Date.Month, Date.Day);
}
static stDate ReadDate(string Message) {
	cout << Message << endl;
	return ReadDate();
}
static stDate ReadDateString() {
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


static short DayOrderInYear(short Year, short Month, short Day)
{
	short CountOfDays = 0;
	for (short i = 1; i < Month; i++) {
		CountOfDays += NumberOfDaysInMonth(i, Year);
	}


	CountOfDays += Day;
	return CountOfDays;
}
static short DayOrderInYear(stDate Date)
{
	short CountOfDays = 0;
	for (short i = 1; i < Date.Month; i++) {
		CountOfDays += NumberOfDaysInMonth(i, Date.Year);
	}


	CountOfDays += Date.Day;
	return CountOfDays;
}
static stDate DateFromDayOrder(short DayOrder, short Year) {
	short RemainingDays = DayOrder;
	short MonthDays = 0;
	stDate Date;
	Date.Year = Year;

	while (true) {
		MonthDays = NumberOfDaysInMonth(Date.Month, Year);

		if (RemainingDays > MonthDays) {
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else {
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}

static bool IsDate1EqualToDate2(stDate Date1, stDate Date2) {
	return
		Date1.Year != Date2.Year ? false : (
			Date1.Month != Date2.Month ? false :
			Date1.Day == Date2.Day);
}
bool IsDateEqualToDate2( stDate Date2) {
	return
		_Date.Year != Date2.Year ? false : (
			_Date.Month != Date2.Month ? false :
			_Date.Day == Date2.Day);
}


static bool IsLastMonthInYear(short Month) {
	return Month == 12;
}
static bool IsLastDayInMonth(stDate Date) {
	return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
}
static bool IsFirstMonthInYear(short Month) {
	return Month == 1;
}
static bool IsFirstDayInMonth(short Day) {
	return Day == 1;
}
static bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {

	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}
static bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
	return IsDate1BeforeDate2(Date2, Date1);
}

static string DateCompareToString(enDateCompare Compare) {
	switch (Compare) {

	case Before: return "Before";
	case Equal: return "Equal";
	case After: return "After";

	}

}
static enDateCompare CompareDates(stDate Date1, stDate Date2) {
	if (IsDate1BeforeDate2(Date1, Date2))
		return Before;
	if (IsDate1AfterDate2(Date1, Date2))
		return After;
	else
		return Equal;
}

static stDate IncreaseDateByOneDay(stDate Date) {
	if (IsLastDayInMonth(Date)) {
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1; Date.Day = 1; Date.Year++;
		}
		else {
			Date.Day = 1;
			Date.Month++;
		}
	}
	else {
		Date.Day++;
	}
	return Date;
}
 void IncreaseDateByOneDay() {
	if (IsLastDayInMonth(_Date)) {
		if (IsLastMonthInYear(_Date.Month))
		{
			_Date.Month = 1; _Date.Day = 1; _Date.Year++;
		}
		else {
			_Date.Day = 1;
			_Date.Month++;
		}
	}
	else {
		_Date.Day++;
	}

}



static stDate IncreaseDateByXDays(stDate Date, short NumberOfDaysToAdd) {

	for (short i = 0; i < NumberOfDaysToAdd; i++) {
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}
void IncreaseDateByXDays( short NumberOfDaysToAdd) {

	for (short i = 0; i < NumberOfDaysToAdd; i++) {
		_Date = IncreaseDateByOneDay(_Date);
	}

}
static stDate IncreaseDateByOneWeek(stDate Date) {

	for (short i = 0; i < 7; i++) {
		Date = IncreaseDateByOneDay(Date);
	}


	return Date;
}
void  IncreaseDateByOneWeek() {

	for (short i = 0; i < 7; i++) {
		_Date = IncreaseDateByOneDay(_Date);
	}
}

static stDate IncreaseDateByXWeeks(stDate Date, short NumberOfWeeksToAdd) {

	for (short i = 0; i < NumberOfWeeksToAdd * 7; i++) {
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

void IncreaseDateByXWeeks( short NumberOfWeeksToAdd) {

	for (short i = 0; i < NumberOfWeeksToAdd * 7; i++) {
		_Date = IncreaseDateByOneDay(_Date);
	}

}
static stDate IncreaseDateByOneMonth(stDate Date) {

	if (IsLastMonthInYear(Date.Month))
		Date.Year++, Date.Month = 1;
	else
		Date.Month++;

	// In Case The Number Of Days In The Past Month Is Greater Than This Month
	short DaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

	if (Date.Day > DaysInCurrentMonth)
		Date.Day = DaysInCurrentMonth;


	return Date;
}
void IncreaseDateByOneMonth() {

	if (IsLastMonthInYear(_Date.Month))
		_Date.Year++, _Date.Month = 1;
	else
		_Date.Month++;

	// In Case The Number Of Days In The Past Month Is Greater Than This Month
	short DaysInCurrentMonth = NumberOfDaysInMonth(_Date.Month, _Date.Year);

	if (_Date.Day > DaysInCurrentMonth)
		_Date.Day = DaysInCurrentMonth;

}

static stDate IncreaseDateByXMonths(stDate Date, short NumberOfWeeksToAdd) {
	for (short i = 0; i < NumberOfWeeksToAdd; i++) {
		IsLastMonthInYear(Date.Month)
			?
			Date.Year++, Date.Month = 1
			:
			Date.Month++;

	}

	return Date;
}
void IncreaseDateByXMonths( short NumberOfWeeksToAdd) {
	for (short i = 0; i < NumberOfWeeksToAdd; i++) {
		IsLastMonthInYear(_Date.Month)
			?
			_Date.Year++, _Date.Month = 1
			:
			_Date.Month++;

	}

}
static stDate IncreaseDateByOneYear(stDate Date) {
	Date.Year++;

	return Date;
}
void IncreaseDateByOneYear() {
	_Date.Year++;
}

static stDate IncreaseDateByXYears(stDate Date, short NumberOfYearsToAdd) {

	for (short i = 0; i < NumberOfYearsToAdd; i++) {

		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}
void IncreaseDateByXYears( short NumberOfYearsToAdd) {

	for (short i = 0; i < NumberOfYearsToAdd; i++) {

		_Date = IncreaseDateByOneYear(_Date);
	}

}
static stDate IncreaseDateByXYearsFaster(stDate Date, short NumberOfYearsToAdd) {
	Date.Year += NumberOfYearsToAdd;

	return Date;
}
void IncreaseDateByXYearsFaster( short NumberOfYearsToAdd) {
	_Date.Year += NumberOfYearsToAdd;

}

static stDate IncreaseDateByOneDecade(stDate Date) {
	Date.Year += 10;

	return Date;
}
void IncreaseDateByOneDecade() {
	_Date.Year += 10;

}

static stDate IncreaseDateByXDecades(stDate Date, short NumberOfDecadesToAdd) {

	for (short i = 0; i < NumberOfDecadesToAdd; i++) {

		Date = IncreaseDateByOneDecade(Date);
	}
	return Date;
}
void IncreaseDateByXDecades( short NumberOfDecadesToAdd) {

	for (short i = 0; i < NumberOfDecadesToAdd; i++) {

		_Date = IncreaseDateByOneDecade(_Date);
	}

}

static stDate IncreaseDateByXDecadesFaster(stDate Date, short NumberOfDecadesToAdd) {
	Date.Year += NumberOfDecadesToAdd * 10;

	return Date;
}
void IncreaseDateByXDecadesFaster( short NumberOfDecadesToAdd) {
	_Date.Year += NumberOfDecadesToAdd * 10;

}


static stDate IncreaseDateByOneCentury(stDate Date) {
	Date.Year += 100;

	return Date;
}
void IncreaseDateByOneCentury() {
	_Date.Year += 100;
}

static stDate IncreaseDateByOneMillennium(stDate Date) {
	Date.Year += 1000;

	return Date;
}
void IncreaseDateByOneMillennium() {
	_Date.Year += 1000;

}

static stDate DecreaseDateByOneDay(stDate Date) {
	if (IsFirstDayInMonth(Date.Day))
		if (IsFirstMonthInYear(Date.Month))
			Date.Month = 12,
			Date.Day = 31,
			Date.Year--;

		else
			Date.Month--,
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);

	else
		Date.Day--;

	return Date;
}
void DecreaseDateByOneDay() {
	if (IsFirstDayInMonth(_Date.Day))
		if (IsFirstMonthInYear(_Date.Month))
			_Date.Month = 12,
			_Date.Day = 31,
			_Date.Year--;

		else
			_Date.Month--,
			_Date.Day = NumberOfDaysInMonth(_Date.Month, _Date.Year);

	else
		_Date.Day--;

}

static stDate DecreaseDateByXDays(stDate Date, short NumberOfDaysToSubtract) {

	for (short i = 0; i < NumberOfDaysToSubtract; i++) {
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}
void DecreaseDateByXDays( short NumberOfDaysToSubtract) {

	for (short i = 0; i < NumberOfDaysToSubtract; i++) {
		_Date = DecreaseDateByOneDay(_Date);
	}

}


static stDate DecreaseDateByOneWeek(stDate Date) {

	for (short i = 0; i < 7; i++) {
		Date = DecreaseDateByOneDay(Date);
	}


	return Date;
}

void DecreaseDateByOneWeek() {

	for (short i = 0; i < 7; i++) {
		_Date = DecreaseDateByOneDay(_Date);
	}

}

static stDate DecreaseDateByXWeeks(stDate Date, short NumberOfWeeksToSubtract) {

	for (short i = 0; i < NumberOfWeeksToSubtract * 7; i++) {
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
void DecreaseDateByXWeeks( short NumberOfWeeksToSubtract) {

	for (short i = 0; i < NumberOfWeeksToSubtract * 7; i++) {
		_Date = DecreaseDateByOneDay(_Date);
	}

}

static stDate DecreaseDateByOneMonth(stDate Date) {

	if (IsFirstMonthInYear(Date.Month))
		Date.Year--, Date.Month = 12;
	else
		Date.Month--;

	// In Case The Number Of Days In The Original Month Is Greater Than This Month
	short DaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

	if (Date.Day > DaysInCurrentMonth)
		Date.Day = DaysInCurrentMonth;


	return Date;
}
void DecreaseDateByOneMonth() {

	if (IsFirstMonthInYear(_Date.Month))
		_Date.Year--, _Date.Month = 12;
	else
		_Date.Month--;

	// In Case The Number Of Days In The Original Month Is Greater Than This Month
	short DaysInCurrentMonth = NumberOfDaysInMonth(_Date.Month, _Date.Year);

	if (_Date.Day > DaysInCurrentMonth)
		_Date.Day = DaysInCurrentMonth;


}

static stDate DecreaseDateByXMonths(stDate Date, short NumberOfMonthsToSubtract) {
	for (short i = 0; i < NumberOfMonthsToSubtract; i++) {
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}

void DecreaseDateByXMonths( short NumberOfMonthsToSubtract) {
	for (short i = 0; i < NumberOfMonthsToSubtract; i++) {
		_Date = DecreaseDateByOneMonth(_Date);
	}


}
static stDate DecreaseDateByOneYear(stDate Date) {
	Date.Year--;

	return Date;
}
void DecreaseDateByOneYear() {
	_Date.Year--;

}

static stDate DecreaseDateByXYears(stDate Date, short NumberOfYearsToSubtract) {

	for (short i = 0; i < NumberOfYearsToSubtract; i++) {

		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}
void DecreaseDateByXYears( short NumberOfYearsToSubtract) {

	for (short i = 0; i < NumberOfYearsToSubtract; i++) {

		_Date = DecreaseDateByOneYear(_Date);
	}

}


static stDate DecreaseDateByXYearsFaster(stDate Date, short NumberOfYearsToSubtract) {
	Date.Year -= NumberOfYearsToSubtract;

	return Date;
}

void DecreaseDateByXYearsFaster(short NumberOfYearsToSubtract) {
	_Date.Year -= NumberOfYearsToSubtract;

}

static stDate DecreaseDateByOneDecade(stDate Date) {
	Date.Year -= 10;

	return Date;
}

void DecreaseDateByOneDecade() {
	_Date.Year -= 10;

}

static stDate DecreaseDateByXDecades(stDate Date, short NumberOfDecadesToSubtract) {

	for (short i = 0; i < NumberOfDecadesToSubtract; i++) {

		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}
void DecreaseDateByXDecades( short NumberOfDecadesToSubtract) {

	for (short i = 0; i < NumberOfDecadesToSubtract; i++) {

		_Date = DecreaseDateByOneDecade(_Date);
	}

}

static stDate DecreaseDateByXDecadesFaster(stDate Date, short NumberOfDecadesToSubtract) {
	Date.Year -= NumberOfDecadesToSubtract * 10;

	return Date;
}
void DecreaseDateByXDecadesFaster( short NumberOfDecadesToSubtract) {
	_Date.Year -= NumberOfDecadesToSubtract * 10;

}


static stDate DecreaseDateByOneCentury(stDate Date) {
	Date.Year -= 100;

	return Date;
}

void DecreaseDateByOneCentury() {
	_Date.Year -= 100;

}


static stDate DecreaseDateByOneMillennium(stDate Date) {
	Date.Year -= 1000;

	return Date;
}

void DecreaseDateByOneMillennium() {
	_Date.Year -= 1000;

}


static void SwapDates(stDate& Date1, stDate& Date2) {
	stDate TempDate;
	TempDate.Year = Date1.Year;
	TempDate.Month = Date1.Month;
	TempDate.Day = Date1.Day;

	Date1.Year = Date2.Year;
	Date1.Month = Date2.Month;
	Date1.Day = Date2.Day;

	Date2.Year = TempDate.Year;
	Date2.Month = TempDate.Month;
	Date2.Day = TempDate.Day;


}

static short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludingLastDay = false) {
	short CountDiff = 0;
	short FlagValue = 1;
	bool IsBefore = IsDate1BeforeDate2(Date1, Date2);
	bool IsEqual = IsDate1EqualToDate2(Date1, Date2);
	if (!IsEqual) {
		if (!IsBefore) {
			SwapDates(Date1, Date2);
			FlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2)) {
			CountDiff++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

	}
	else
		return 0;

	return IncludingLastDay ? ++CountDiff * FlagValue : CountDiff * FlagValue;
}
static short GetPeriodLengthInDays(stPeriod Period, bool IncludingLastDay = false) {
	return GetDifferenceInDays(Period.Start, Period.End, IncludingLastDay);
}
static bool IsDateInPeriod(stPeriod Period, stDate Date) {

	return !(
		CompareDates(Date, Period.Start) == enDateCompare::Before ||
		CompareDates(Date, Period.End) == enDateCompare::After
		);

}



static string GetDayLongName(stDate Date) {
	return DayLongName(DayOfWeekOrder(Date));
}
static string GetDayShortName(stDate Date) {
	return DayShortName(DayOfWeekOrder(Date));
}

static bool IsEndOfWeek(stDate Date) {

	return DayOfWeekOrder(Date) == 6;
}
static bool IsAWeekEnd(stDate Date) {
	short DayOrder = DayOfWeekOrder(Date);
	return (DayOrder == 5 || DayOrder == 6);
}
static bool IsABusinessDay(stDate Date) {
	return !IsAWeekEnd(Date);
}

static short DaysUntillEndOfWeek(stDate Date) {

	return 6 - DayOfWeekOrder(Date);
}

static short DaysUntillEndOfMonth(stDate Date) {

	stDate EndOfMonth = Date;
	EndOfMonth.Day = NumberOfDaysInMonth(Date);

	return GetDifferenceInDays(Date, EndOfMonth, true);
}

static short DaysUntillEndOfYear(stDate Date) {
	stDate EndOfYear;
	EndOfYear.Day = 31;
	EndOfYear.Month = 12;
	EndOfYear.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfYear, true);
}
static short HowManyDaysHavePassedSince(stDate Date, bool IncludeLastDay = true) {
	return GetDifferenceInDays(Date, GetSystemDate(), IncludeLastDay);
}

static bool IsPeriodsOverlapping(stPeriod Period1, stPeriod Period2) {


	if (
		CompareDates(Period1.End, Period2.Start) == Before ||
		CompareDates(Period2.End, Period1.Start) == Before
		)
		return false;

	else
		return true;
}
static short CountOverlappingDays(stPeriod Period1, stPeriod Period2) {
	if (!IsPeriodsOverlapping(Period1, Period2))
		return 0;

	bool IsPeriod1Longer = GetPeriodLengthInDays(Period1) > GetPeriodLengthInDays(Period2);
	if (IsPeriod1Longer)
		swap(Period1, Period2);/// So We Don't go Through The Longer One

	/// Now Period1 is Shorter Than Period2 so we go From The Start Of Period1 To The End Of Period1
	/// We Check Each Day If Its In Period2 Or Not

	int OverlapDays = 0;
	while (CompareDates(Period1.Start, Period1.End) == Before) {
		if (IsDateInPeriod(Period2, Period1.Start))
			OverlapDays++;
		Period1.Start = IncreaseDateByOneDay(Period1.Start);
	}
	return OverlapDays;
}


static void PrintMonthCalendar(short Month, short Year)
{
	short NumberOfDays = NumberOfDaysInMonth(Month, Year);
	short FirstDayInTheMonth = DayOfWeekOrder(Year, Month, 1);

	printf("\n  ______________ %s ______________ \n", MonthShortName(Month).c_str());
	printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat \n\n");

	short i;
	for (i = 0; i < FirstDayInTheMonth; i++)
	{
		printf("     ");
	}
	for (short j = 1; j <= NumberOfDays; j++) {
		printf("%5d", j);
		if (++i == 7) {
			i = 0;
			printf("\n");
		}
	}
	printf("\n\n  _________________________________ \n\n");

}
 void PrintMonthCalendar()
{
	short NumberOfDays = NumberOfDaysInMonth(_Date.Month, _Date.Year);
	short FirstDayInTheMonth = DayOfWeekOrder(_Date.Year, _Date.Month, 1);

	printf("\n  ______________ %s ______________ \n", MonthShortName(_Date.Month).c_str());
	printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat \n\n");

	short i;
	for (i = 0; i < FirstDayInTheMonth; i++)
	{
		printf("     ");
	}
	for (short j = 1; j <= NumberOfDays; j++) {
		printf("%5d", j);
		if (++i == 7) {
			i = 0;
			printf("\n");
		}
	}
	printf("\n\n  _________________________________ \n\n");

}
static void PrintYearCalendar(short Year) {
	printf("\n\n  _________________________________ \n\n");
	printf("\t   Calendar - %d ", Year);
	printf("\n\n  _________________________________ \n\n");

	for (int i = 1; i <= 12; i++)
		PrintMonthCalendar(i, Year);


}
void PrintYearCalendar() {
	printf("\n\n  _________________________________ \n\n");
	printf("\t   Calendar - %d ", _Date.Year);
	printf("\n\n  _________________________________ \n\n");

	for (int i = 1; i <= 12; i++)
		PrintMonthCalendar(i, _Date.Year);


}

};
