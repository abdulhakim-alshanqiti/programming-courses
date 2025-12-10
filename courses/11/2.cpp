#include <iostream>
#include "../../libs/clsInputValidate.h"

int main()

{
    cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),
        clsDate(8, 12, 2022),
        clsDate(31, 12, 2022)) << endl;
     
    cout << clsInputValidate::IsDateBetween(clsDate(),
        clsDate(31, 12, 2022),
        clsDate(8, 12, 2022)) << endl;


    int x = clsInputValidate::ReadIntNumber("Please Enter A Number", "Invalid Number, Enter again:\n");
    cout << "x=" << x<< endl;


    int y = clsInputValidate::ReadIntNumberBetween(1, 5, "Please Enter A Number in Range","Number is not within range, enter again:\n");
    cout << "y=" << y << endl;


    double a = clsInputValidate::ReadDblNumber("Please Enter A Double", "Invalid Number, Enter again:\n");
    cout << "a=" << a << endl;


    double b = clsInputValidate::ReadDblNumberBetween(1, 5, "Please Enter A Double", "Number is not within range, enter again:\n");
    cout << "b=" << b << endl;

    cout << endl << clsInputValidate::IsValidDate(clsDate(35, 12, 2022)) << endl;

    system("pause>0");

    return 0;
}