#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../../../../libs/clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber(string message)
    {
        string AccountNumber = "";
        cout << message;
        cin >> AccountNumber;
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            cout << message;
            cin >> AccountNumber;
        }

        return AccountNumber;

    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t   Transfer Screen");

        clsBankClient SourceClient  = 
            clsBankClient::Find(
                _ReadAccountNumber("Enter The Account Number You Want To Transfer From")
            );


        _PrintClient(SourceClient);


        clsBankClient DestinationClient =
            clsBankClient::Find(
                _ReadAccountNumber("Enter The Account Number You Want To Transfer To")
            );

        _PrintClient(DestinationClient);


        double Amount = 0;
        cout << "\nPlease Enter Transfer Amount ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
            {
                cout << "\nAmount Transferred Successfully.\n";
                _PrintClient(SourceClient);
                _PrintClient(DestinationClient);

            }
            else {
                cout << "\nOperation Failed There Is Not Enough Money In Your Account To Make This Transfer.\n";
            }

    
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }



    }

};

