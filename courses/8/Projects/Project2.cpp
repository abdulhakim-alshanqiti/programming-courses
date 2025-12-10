#include <string>

#include "../../../libs/MyLib.h"
#include "../../../libs/Date.h"
#include<fstream>
#include<iomanip>

using namespace std;
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;

const string ClientsFilePath = "./courses/8/Projects/Project2.txt";

struct stClientRecord {
	string	AccountId = "";
	string	PinCode = "";
	string	Name = "";
	string	Phone = "";
	double	AccountBalance = 0.0;
	bool MarkForDeletion = false;
};
stClientRecord CurrentClient;


enum enMainMenuScreens {
	QuickWithDraw = 1,
	NormalWithDraw = 2,
	Deposit = 3,
	CheckBalance = 4,
	Logout= 5,
};




void Login();
void ShowMainMenuScreen();

void ShowQuickWithDrawScreen();

void PrintLine(string StringToRepeat = "_") {
	cout << "\n" << RepeatString(92, StringToRepeat) << "\n\n";
}


bool ReadBool(string Message) {
	char Answer = 'y';
	do {
		Answer = ReadChar(Message);
	} while (toupper(Answer) != 'Y' && toupper(Answer) != 'N');

	return    (toupper(Answer) == 'Y') ? true : false;
}

bool FindClientByAccountIdAndPincode(stClientRecord& TempClientRecord, vector<stClientRecord>& vClientsRecords, string AccountId, string PinCode) {



	for (stClientRecord& ClientRecord : vClientsRecords)
	{
		if (ClientRecord.AccountId == AccountId && ClientRecord.PinCode == PinCode)
		{
			TempClientRecord = ClientRecord;
			return true;
		}
	}


	return false;
}




bool TryLogin(vector<stClientRecord>& vClientsRecords, string AccountId, string PinCode) {
	return FindClientByAccountIdAndPincode(CurrentClient, vClientsRecords, AccountId, PinCode);
}

void AddClientRecordToFile(string ClientRecord) {
	fstream MyFile;

	MyFile.open(ClientsFilePath, ios::out | ios::app);



	if (MyFile.is_open()) {

		MyFile << ClientRecord << endl;

	}
	MyFile.close();
}
bool DoesClientExistByAccountId(string AccountId, vector<stClientRecord>& vClientsRecords) {

	for (stClientRecord& ClientRecord : vClientsRecords)
	{
		if (ClientRecord.AccountId == AccountId)
		{
			return true;
		}
	}


	return false;
}

string ClientRecordToString(stClientRecord Client, string Separator = "#//#") {
	string sClientRecord = "";

	sClientRecord += Client.AccountId + Separator;
	sClientRecord += Client.PinCode + Separator;
	sClientRecord += Client.Name + Separator;
	sClientRecord += Client.Phone + Separator;
	sClientRecord += to_string(Client.AccountBalance);

	return sClientRecord;
}



stClientRecord ClientRecordFromString(string sClientRecord, string Separator = "#//#") {

	vector<string> vSections = SplitString(sClientRecord, Separator);
	stClientRecord ClientRecord;

	ClientRecord.AccountId = vSections[0];
	ClientRecord.PinCode = vSections[1];
	ClientRecord.Name = vSections[2];
	ClientRecord.Phone = vSections[3];
	ClientRecord.AccountBalance = stod(vSections[4]);
	ClientRecord.MarkForDeletion = false;

	return ClientRecord;
}
vector<stClientRecord> GetClientsFromFile() {
	vector<stClientRecord> vClientsRecords;

	fstream MyFile;

	string line = "";
	stClientRecord ClientRecord;

	MyFile.open(ClientsFilePath, ios::in);

	if (MyFile.is_open()) {
		while (getline(MyFile, line)) {

			ClientRecord = ClientRecordFromString(line);
			vClientsRecords.push_back(ClientRecord);
		}
	}

	MyFile.close();

	return vClientsRecords;
}






void PrintClientCard(stClientRecord ClientRecord) {
	PrintLine();
	cout
		<< "Account ID :" << ClientRecord.AccountId << endl
		<< "Pin Code :" << ClientRecord.PinCode << endl
		<< "Name :" << ClientRecord.Name << endl
		<< "Phone :" << ClientRecord.Phone << endl
		<< "Account Balance  :" << to_string(ClientRecord.AccountBalance) << endl;
	PrintLine();
}



bool FindClientByAccountId(stClientRecord& TempClientRecord, vector<stClientRecord>& vClientsRecords, string AccountIdToSearchFor) {



	for (stClientRecord& ClientRecord : vClientsRecords)
	{
		if (ClientRecord.AccountId == AccountIdToSearchFor)
		{
			TempClientRecord = ClientRecord;
			return true;
		}
	}


	return false;
}

void SaveClientsDataToFile(vector<stClientRecord>& vClientsRecords) {
	fstream MyFile;
	string Line = "";
	MyFile.open(ClientsFilePath, ios::out);

	if (MyFile.is_open()) {
		for (stClientRecord& ClientRecord : vClientsRecords) {
			if (ClientRecord.MarkForDeletion == false) {
				Line = ClientRecordToString(ClientRecord);
				MyFile << Line << endl;
			}

		}
	}
	MyFile.close();
}


void ChangeAmmountInAccount( bool Deposit, double ChangeAmmount = 0) {

	string Message = Deposit ? "Please Enter The Ammount You Want To Deposit" : "Please Enter The Ammount You Want To WithDraw";

	if (!Deposit && (ChangeAmmount > CurrentClient.AccountBalance)) {
		Printl("Your Account Dosen't Have Enough Balance \n Press Any Key To Make Another Choice");
		system("pause>0");
		system("cls");
		return ShowQuickWithDrawScreen();
	}
	vector<stClientRecord> vClientsRecords = GetClientsFromFile();

	for (stClientRecord& ClientRecord : vClientsRecords) {

		if (ClientRecord.AccountId == CurrentClient.AccountId) {
	

			if (Deposit) {
				ChangeAmmount = (double)ReadPositiveNumber("Please Enter The Ammount You Want To Deposit");

			}
			else {

				if (ChangeAmmount == 0)   
					ChangeAmmount = (double)
					ReadNumberInRange("Please Enter The Ammount You Want To WithDraw Must Be Less Than Or Equal To" + to_string(ClientRecord.AccountBalance), 1, ClientRecord.AccountBalance);
			
				 
				 ChangeAmmount *= -1;

			}
			char AreYouSure = 'n';
			AreYouSure = ReadChar("Are You Sure You Want To Perform This Action ?");
			if (toupper(AreYouSure) == 'Y') {

				ClientRecord.AccountBalance = ClientRecord.AccountBalance + ChangeAmmount;
				CurrentClient = ClientRecord;
				Printl("The New Balance Ammount Is " + to_string(ClientRecord.AccountBalance));
				break;
			}
		}

	}


	SaveClientsDataToFile(vClientsRecords);
}

void ScreenTitle(string Name) {

	PrintLine("-");
	Printl("\t\t" + Name + " Screen");
	PrintLine("-");

}

void ShowBalance() {
	Printl("Your Account Balance :" + to_string(CurrentClient.AccountBalance));
}
void ShowCheckBalanceScreen() {

	ScreenTitle("Check Balance");
	ShowBalance();
}

void ShowDepositScreen() {

	ScreenTitle("Deposit");

	ShowBalance();
	ChangeAmmountInAccount( true);

}
void ShowQuickWithDrawScreen() {
	ScreenTitle("Quick WithDraw");

	PrintLine("=");
	Printl("\t [1] 20  \t[2] 50");
	Printl("\t [3] 100 \t[4] 200");
	Printl("\t [5] 400 \t[6] 600");
	Printl("\t [7] 800 \t[8] 1000");
	Printl("\t [9] Exit");

	PrintLine("=");
	ShowBalance();

	short QuickWithDrawOption = ReadNumberInRange("What Do You Want To Do ? \nEnter a Number [1 to 9]", 1, 9);
	if	(QuickWithDrawOption == 9)  return;	

	short Ammount[] = { 0, 20,50,100,200,400,600,800,1000};

	ChangeAmmountInAccount(false, Ammount[QuickWithDrawOption]);
}

void ShowWithDrawScreen() {
	ScreenTitle("WithDraw");
	ShowBalance();
	short WithDrawAmmount= 5;
	do {
		WithDrawAmmount =  ReadNumberInRange("Enter An Amount That Is mulitples Of 5's ? ", 5, INT_MAX);

	} while (WithDrawAmmount % 5 != 0);


	ChangeAmmountInAccount( false, WithDrawAmmount);

}

void GoBackToMainMenu() {
	PrintLine();
	Printl("\t\tPress Any Key To Go Back To Main Menu");
	PrintLine();

	system("pause>0");
	ShowMainMenuScreen();
}



void GoToMainMenuScreens(enMainMenuScreens Screen) {
	system("cls");

	switch (Screen)
	{

	case QuickWithDraw:
		ShowQuickWithDrawScreen(); break;

	case NormalWithDraw:
		ShowWithDrawScreen(); break;

	case Deposit:
		ShowDepositScreen(); break;

	case CheckBalance:
		ShowCheckBalanceScreen(); break;

	case Logout: 
		return Login();

	}
	GoBackToMainMenu();


}





void ShowMainMenuScreen() {
	system("cls");
	PrintLine("=");

	Printl("\t Main Menu Screen");
	PrintLine("=");

	Printl("\t [1] Quick WithDraw");
	Printl("\t [2] Normal WithDraw");
	Printl("\t [3] Deposit");
	Printl("\t [4] Check Balance");
	Printl("\t [5] Logout");


	PrintLine("=");

	enMainMenuScreens Screen = (enMainMenuScreens)
		ReadNumberInRange("What Do You Want To Do ? \nEnter a Number [1 to 5]", 1, 5);
	
	GoToMainMenuScreens(Screen);

}



void Login() {


	vector<stClientRecord> vClientsRecords = GetClientsFromFile();
	bool LoginFailed = false;

	string AccountId = "";
	string PinCode = "";


	do {
		system("cls");
		PrintLine("=");
		Printl("\t Login Screen");
		PrintLine("=");

		if (LoginFailed)
			Printl("Invalid Account ID/Pin Code");

		AccountId = ReadStringWS("Enter Your Account ID");
		PinCode = ReadStringWS("Enter Your Pin Code");

		LoginFailed = !TryLogin(vClientsRecords, AccountId, PinCode);

	} while (LoginFailed);

	ShowMainMenuScreen();

}

int main() {


	Login();


	return 0;
}