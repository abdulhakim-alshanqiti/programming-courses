#pragma once
#include "clsDate.h"

class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After
            )
            return false;
        else
            return true;

    }


    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }
    short GetPeriodLengthInDays( bool IncludingLastDay = false) {
        return  clsDate::GetDifferenceInDays(StartDate, EndDate, IncludingLastDay);
    }
    static short GetPeriodLengthInDays(clsPeriod Period, bool IncludingLastDay = false) {
        return  clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludingLastDay);
    }
    static bool IsDateInPeriod(clsPeriod Period, clsDate Date) {

        return !(
            clsDate:: CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before ||
            clsDate::  CompareDates(Date, Period.EndDate) == clsDate::enDateCompare::After
            );

    }


    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();


    }

};
