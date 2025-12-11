#pragma once

#include <iostream>
#include <fstream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include "../../../../libs/clsString.h"
class clsLoginScreen :protected clsScreen
{

private :


  static  bool _Login()
    {
        bool LoginFailed = false;
        short FailedLoginCounter = 0;
        string Username, Password;
        do
        {
     
            if (LoginFailed)
            {
                FailedLoginCounter++;
                cout << "\nInvalid Username/Password! \n\nYou Have " << 3 - FailedLoginCounter  << " Tries Left\n\n";
            }
            if (FailedLoginCounter == 3) {
                cout << "You Have Failed To Login 3 Times \nYou Are Locked ! ";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);

        CurrentUser.RegisterLogIn();

        clsMainScreen::ShowMainMenue();
        return true;
    }

public:



    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};

