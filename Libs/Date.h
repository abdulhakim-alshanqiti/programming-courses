#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "MyLib.h"
using Input::ReadPositiveNumber;

namespace Date {

	struct stDate {
		short Year = 1;
		short Month = 1;
		short Day = 1;
	};
	stDate ReadDate(short Year = 0, short Month = 0, short Day = 0) {
		stDate Date;
		Date.Year = (Year == 0) ? ReadPositiveNumber("Enter A Year") : Year;
		Date.Month = (Month == 0) ? ReadPositiveNumber("Enter A Month") : Month;
		Date.Day = (Day == 0) ? ReadPositiveNumber("Enter A Day") : Day;
		return Date;
	}


	string DayLongName(short Day) {
		string arrDaysOfWeek[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
		return arrDaysOfWeek[Day];

	}
	string DayShortName(short Day) {
		string arrDaysOfWeek[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDaysOfWeek[Day];

	}

	string MonthLongName(short Month) {
		string arrOfMonth[13] = { "", "January","February","March","April","May","June","July","August","September","October","November","December" };
		return arrOfMonth[Month];
	}
	string MonthShortName(short Month) {
		string arrOfMonth[13] = { "", "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return arrOfMonth[Month];
	}


	short DayOfWeekOrder(short Year, short Month, short Day) {
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DayOfWeekOrder(stDate Date) {
		return DayOfWeekOrder(Date.Year,Date.Month,Date.Day);
	}
	bool IsLeapYear(short year) {
		return   (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
	}
	short NumberOfDaysInMonth(short Month, short Year) {
		if (Month < 1 || Month > 12)
			return 0;

		short NumberOfDaysInEachMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		return	(Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDaysInEachMonth[Month];
	}
	short NumberOfDaysInMonth(stDate Date) {
		return NumberOfDaysInMonth( Date.Month, Date. Year);
	}
	short NumberOfDaysInYear(short Year) {
		return  (IsLeapYear(Year) ? 366 : 365);
	}
	short NumberOfDaysInYear(stDate Date) {
		return NumberOfDaysInYear(Date.Year) ;
	}


	short NumberOfHoursInMonth(short Month, short Year) {
		return NumberOfDaysInMonth(Month, Year) * 24;
	}
	int NumberOfMinutesInMonth(short Month, short Year) {
		return NumberOfHoursInMonth(Month, Year) * 60;
	}
	int NumberOfSecondsInMonth(short Month, short Year) {
		return NumberOfMinutesInMonth(Month, Year) * 60;
	}
	short NumberOfHoursInYear(short Year) {
		return NumberOfDaysInYear(Year) * 24;
	}
	int NumberOfMinutesInYear(short Year) {
		return NumberOfHoursInYear(Year) * 60;
	}
	int NumberOfSecondsInYear(short Year) {
		return NumberOfMinutesInYear(Year) * 60;
	}


	short DayOrderInYear(short Year, short Month, short Day)
	{
		short CountOfDays = 0;
		for (short i = 1; i < Month; i++) {
			CountOfDays += NumberOfDaysInMonth(i, Year);
		}


		CountOfDays += Day;
		return CountOfDays;
	}
	short DayOrderInYear(stDate Date)
	{
		short CountOfDays = 0;
		for (short i = 1; i < Date.Month; i++) {
			CountOfDays += NumberOfDaysInMonth(i, Date.Year);
		}


		CountOfDays += Date.Day;
		return CountOfDays;
	}
	stDate DateFromDayOrder(short DayOrder, short Year) {
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

	bool IsDate1EqualToDate2(stDate Date1, stDate Date2) {
		return
			Date1.Year != Date2.Year ? false : (
				Date1.Month != Date2.Month ? false :
				Date1.Day == Date2.Day);
	}

	bool IsLastMonthInYear(short Month) {
		return Month == 12;
	}
	bool IsLastDayInMonth(stDate Date) {
		return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
	}
	bool IsFirstMonthInYear(short Month) {
		return Month == 1;
	}
	bool IsFirstDayInMonth(short Day) {
		return Day == 1;
	}
	bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {

		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false); 

	}

	stDate IncreaseDateByOneDay(stDate Date) {
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


	stDate IncreaseDateByXDays(stDate Date, short NumberOfDaysToAdd) {

		for (short i = 0; i < NumberOfDaysToAdd; i++) {
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	stDate IncreaseDateByOneWeek(stDate Date) {

		for (short i = 0; i < 7; i++) {
			Date = IncreaseDateByOneDay(Date);
		}


		return Date;
	}

	stDate IncreaseDateByXWeeks(stDate Date, short NumberOfWeeksToAdd) {

		for (short i = 0; i < NumberOfWeeksToAdd * 7; i++) {
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	stDate IncreaseDateByOneMonth(stDate Date) {

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

	stDate IncreaseDateByXMonths(stDate Date, short NumberOfWeeksToAdd) {
		for (short i = 0; i < NumberOfWeeksToAdd; i++) {
			IsLastMonthInYear(Date.Month)
				?
				Date.Year++, Date.Month = 1
				:
				Date.Month++;

		}

		return Date;
	}
	stDate IncreaseDateByOneYear(stDate Date) {
		Date.Year++;

		return Date;
	}
	stDate IncreaseDateByXYears(stDate Date, short NumberOfYearsToAdd) {

		for (short i = 0; i < NumberOfYearsToAdd; i++) {

			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}

	stDate IncreaseDateByXYearsFaster(stDate Date, short NumberOfYearsToAdd) {
		Date.Year += NumberOfYearsToAdd;

		return Date;
	}


	stDate IncreaseDateByOneDecade(stDate Date) {
		Date.Year += 10;

		return Date;
	}
	stDate IncreaseDateByXDecades(stDate Date, short NumberOfDecadesToAdd) {

		for (short i = 0; i < NumberOfDecadesToAdd; i++) {

			Date = IncreaseDateByOneDecade(Date);
		}
		return Date;
	}

	stDate IncreaseDateByXDecadesFaster(stDate Date, short NumberOfDecadesToAdd) {
		Date.Year += NumberOfDecadesToAdd * 10;

		return Date;
	}


	stDate IncreaseDateByOneCentury(stDate Date) {
		Date.Year += 100;

		return Date;
	}


	stDate IncreaseDateByOneMillennium(stDate Date) {
		Date.Year += 1000;

		return Date;
	}

	stDate DecreaseDateByOneDay(stDate Date) {
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

	stDate DecreaseDateByXDays(stDate Date, short NumberOfDaysToSubtract) {

		for (short i = 0; i < NumberOfDaysToSubtract; i++) {
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	stDate DecreaseDateByOneWeek(stDate Date) {

		for (short i = 0; i < 7; i++) {
			Date = DecreaseDateByOneDay(Date);
		}


		return Date;
	}

	stDate DecreaseDateByXWeeks(stDate Date, short NumberOfWeeksToSubtract) {

		for (short i = 0; i < NumberOfWeeksToSubtract * 7; i++) {
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	stDate DecreaseDateByOneMonth(stDate Date) {

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

	stDate DecreaseDateByXMonths(stDate Date, short NumberOfMonthsToSubtract) {
		for (short i = 0; i < NumberOfMonthsToSubtract; i++) {
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}
	stDate DecreaseDateByOneYear(stDate Date) {
		Date.Year--;

		return Date;
	}
	stDate DecreaseDateByXYears(stDate Date, short NumberOfYearsToSubtract) {

		for (short i = 0; i < NumberOfYearsToSubtract; i++) {

			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	stDate DecreaseDateByXYearsFaster(stDate Date, short NumberOfYearsToSubtract) {
		Date.Year -= NumberOfYearsToSubtract;

		return Date;
	}


	stDate DecreaseDateByOneDecade(stDate Date) {
		Date.Year -= 10;

		return Date;
	}
	stDate DecreaseDateByXDecades(stDate Date, short NumberOfDecadesToSubtract) {

		for (short i = 0; i < NumberOfDecadesToSubtract; i++) {

			Date = DecreaseDateByOneDecade(Date);
		}
		return Date;
	}

	stDate DecreaseDateByXDecadesFaster(stDate Date, short NumberOfDecadesToSubtract) {
		Date.Year -= NumberOfDecadesToSubtract * 10;

		return Date;
	}


	stDate DecreaseDateByOneCentury(stDate Date) {
		Date.Year -= 100;

		return Date;
	}


	stDate DecreaseDateByOneMillennium(stDate Date) {
		Date.Year -= 1000;

		return Date;
	}
	void SwapDates(stDate& Date1, stDate& Date2) {
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
	short GetDiffBettwenTwoDates(stDate Date1, stDate Date2, bool WithLastDay = false) {
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

		return WithLastDay ? CountDiff * FlagValue : (++CountDiff) * FlagValue;
	}

	stDate GetSystemDate() {
		stDate Date;
		time_t t = time(0);
		// get time now 
		tm* now = localtime(&t);
		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;
	}

	string GetDayLongName(stDate Date) {
		return DayLongName(DayOfWeekOrder(Date));
	}
	string GetDayShortName(stDate Date) {
		return DayShortName(DayOfWeekOrder(Date));
	}

	bool IsEndOfWeek(stDate Date) {

		return DayOfWeekOrder(Date) == 6;
	}
	bool IsAWeekEnd(stDate Date) {
		short DayOrder = DayOfWeekOrder(Date);
		return (DayOrder == 5 || DayOrder == 6);
	}
	bool IsABusinessDay(stDate Date) {
		return !IsAWeekEnd(Date);
	}

	short DaysUntillEndOfWeek(stDate Date) {

		return 6 - DayOfWeekOrder(Date);
	}

	short DaysUntillEndOfMonth(stDate Date) {

		stDate EndOfMonth = Date;
		EndOfMonth.Day = NumberOfDaysInMonth(Date);

		return GetDiffBettwenTwoDates(Date, EndOfMonth, true);
	}

	short DaysUntillEndOfYear(stDate Date) {
		stDate EndOfYear;
		EndOfYear.Day = 31;
		EndOfYear.Month = 12;
		EndOfYear.Year = Date.Year;

		return GetDiffBettwenTwoDates(Date, EndOfYear, true);
	}
	short HowManyDaysHavePassedSince(stDate Date, bool IncludeLastDay = true) {
		return GetDiffBettwenTwoDates(Date, GetSystemDate(), IncludeLastDay);
	}


	void PrintMonthCalendar(short Month, short Year)
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
	void PrintYearCalendar(short Year) {
		printf("\n\n  _________________________________ \n\n");
		printf("\t   Calendar - %d ", Year);
		printf("\n\n  _________________________________ \n\n");

		for (int i = 1; i <= 12; i++)
			PrintMonthCalendar(i, Year);


	}
}
