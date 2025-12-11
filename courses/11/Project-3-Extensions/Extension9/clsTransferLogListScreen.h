#pragma once

#include "clsScreen.h"
#include <iomanip>
#include <vector>
#include <vector>
#include "clsUser.h"
#include "clsBankClient.h"


class clsTransferLogListScreen :protected clsScreen
{

private:

    static void PrintTransferRegisterRecordLine(clsBankClient::stTransferRegisterRecord TransferRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << TransferRegisterRecord.DateTime;
        cout << "| " << setw(10) << left << TransferRegisterRecord.SourceAccountNumber;
        cout << "| " << setw(10) << left << TransferRegisterRecord.DestinationAccountNumber;
        cout << "| " << setw(10) << left << TransferRegisterRecord.Amount;
        cout << "| " << setw(10) << left << TransferRegisterRecord.srcBalance;
        cout << "| " << setw(10) << left << TransferRegisterRecord.desBalance;
        cout << "| " << setw(10) << left << TransferRegisterRecord.UserName;

    }

public:

    static void ShowTransferLogListScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTransferRegisterList))
        {
            return;// this will exit the function and it will not continue
        }
        vector <clsBankClient::stTransferRegisterRecord> vTransferRegisterRecord = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Register List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acc";
        cout << "| " << left << setw(10) << "d.Acc";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferRegisterRecord Record : vTransferRegisterRecord)
            {

                PrintTransferRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

