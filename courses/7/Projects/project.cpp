#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include "../../../libs/MyLib.h"
using namespace Input;
using namespace std;
using namespace Strings;
using namespace Output;
struct stClientRecord {
	string	AccountId = "";
	string	PinCode = "";
	string	Name = "";
	string	Phone = "";
	double	AccountBalance = 0.0;
	bool MarkForDeletion = false;
};
enum enMainMenuScreens {
	ClientList = 1,
	NewClient = 2,
	DeleteClient = 3,
	UpdateClientInfo = 4,
	FindClient = 5,
	Exit = 6,
};
const string ClientsFilePath = "./courses/7/Projects/project2.txt";

void ShowMainMenuScreen();




void PrintLine(string StringToRepeat = "_") {
	cout << "\n" << RepeatString(92, StringToRepeat) << "\n\n";
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
string ReadUniqueAccountId() {
	vector<stClientRecord> vClientsRecords = GetClientsFromFile();

	string AccountId = ReadStringWS("Please Enter Your Account ID");

	while (DoesClientExistByAccountId(AccountId, vClientsRecords))
	{
		Printl("The Account ID Already Exist \nPlease Choose A Diffirent ID");
		AccountId = ReadStringWS("Please Enter Your Account ID");
	}

	return AccountId;
}


stClientRecord ReadClientRecord(string AccountId = "") {

	stClientRecord ClientRecord;
	ClientRecord.AccountId = (AccountId == "") ? ReadUniqueAccountId() : AccountId;

	ClientRecord.PinCode = ReadStringWS("Please Enter Your Pin Code");
	ClientRecord.Name = ReadString("Please Enter Your Name");
	ClientRecord.Phone = ReadString("Please Enter Your Phone Number");
	ClientRecord.AccountBalance = ReadPositiveNumber("Please Enter Your Account Balance");

	return ClientRecord;
}


void PrintClientCard(stClientRecord ClientRecord) {
	PrintLine();
	cout
		<< "Account ID :" << ClientRecord.AccountId << endl
		<< "Pin Code :" << ClientRecord.PinCode << endl
		<< "Name :" << ClientRecord.Name << endl
		<< "Phone :" << ClientRecord.Phone << endl
		<< "Account Balance  :" << ClientRecord.AccountBalance << endl;
	PrintLine();
}





void PrintColumnsNames() {
	cout
		<< " | " << left << setw(15) << "Account ID"
		<< " | " << left << setw(10) << "PinCode"
		<< " | " << left << setw(22) << "Name"
		<< " | " << left << setw(15) << "Phone"
		<< " | " << left << setw(10) << "Balance";
}
void PrintTableHead() {
	PrintLine();
	PrintColumnsNames();
	PrintLine();
}

void PrintClientRecord(stClientRecord ClientRecord) {

	cout
		<< " | " << left << setw(15) << ClientRecord.AccountId
		<< " | " << left << setw(10) << ClientRecord.PinCode
		<< " | " << left << setw(22) << ClientRecord.Name
		<< " | " << left << setw(15) << ClientRecord.Phone
		<< " | " << left << setw(10) << ClientRecord.AccountBalance << endl;

}
void PrintTableBody(vector<stClientRecord>& vClientsRecords) {

	for (stClientRecord& CLientRecord : vClientsRecords) {
		PrintClientRecord(CLientRecord);
	}
	PrintLine();
}
void PrintAllClientsData(vector<stClientRecord> vClientsRecords) {
	if (vClientsRecords.size() == 0)
		Printl("No CLients Available In The System");
	else {
		cout << "\t\t\t\t" << "Client List (" << vClientsRecords.size() << ") Client(s)." << endl;

		PrintTableHead();
		PrintTableBody(vClientsRecords);
	}

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

void UpdateClientRecord(vector<stClientRecord>& vClientsRecords, stClientRecord& ClientRecordToUpdate) {
	char AreYouSure = 'n';
	AreYouSure = ReadChar("Are You Sure You Want To Update Record ?");
	if (toupper(AreYouSure) == 'Y') {

		for (stClientRecord& ClientRecord : vClientsRecords)
		{
			if (ClientRecord.AccountId == ClientRecordToUpdate.AccountId)
			{
				ClientRecord = ReadClientRecord(ClientRecord.AccountId);

				break;
			}
		}

		SaveClientsDataToFile(vClientsRecords);


		Printl("Record Updated Succesfully");
	}
}

void DeleteClientRecord(vector<stClientRecord>& vClientsRecords, stClientRecord& ClientRecordToDelete) {
	char AreYouSure = 'n';
	AreYouSure = ReadChar("Are You Sure You Want To Delete Record ?");
	if (toupper(AreYouSure) == 'Y') {

		for (stClientRecord& ClientRecord : vClientsRecords)
		{
			if (ClientRecord.AccountId == ClientRecordToDelete.AccountId)
			{
				ClientRecord.MarkForDeletion = true;

				break;
			}
		}

		SaveClientsDataToFile(vClientsRecords);
		Printl("Record Deleted Succesfully");
	}
}

void AddNewClient() {

	vector<stClientRecord> vClientsRecords = GetClientsFromFile();


	vClientsRecords.push_back(ReadClientRecord());
	SaveClientsDataToFile(vClientsRecords);
}

void ScreenTitle(string Name) {

	PrintLine("-");
	Printl("\t\t" + Name + " Screen");
	PrintLine("-");
}


void ShowExitScreen() {

	PrintLine();

	Printl("\t The Program Has Exited");
	PrintLine();


}

void ShowClientListScreen() {
	vector<stClientRecord> vClientsRecords = GetClientsFromFile();

	PrintAllClientsData(vClientsRecords);

}
void ShowNewClientScreen() {

	ScreenTitle("New Client");

	char AddMore = 'Y';

	while (toupper(AddMore) == 'Y')
	{
		system("cls");
		AddNewClient();
		AddMore = ReadChar("Client Added Successfully \nDo You Want To Add More Clients?");

	}

}
void ShowDeleteClientScreen() {

	ScreenTitle("Delete Client");
	string Message = "Please Enter The Account ID You Want To Delete";

	string AccountId = ReadStringWS(Message);
	stClientRecord ClientRecord;

	vector<stClientRecord> vClientsRecords = GetClientsFromFile();
	while (!FindClientByAccountId(ClientRecord, vClientsRecords, AccountId))
	{
		Printl("The Account ID Doesn't Exist \nPlease Make Sure You Entered The Correct Number");
		AccountId = ReadStringWS(Message);
	}

	DeleteClientRecord(vClientsRecords, ClientRecord);




}

void ShowUpdateClientScreen() {
	ScreenTitle("Update Client");
	string Message = "Please Enter The Account ID You Want To Update";

	string AccountId = ReadStringWS(Message);
	stClientRecord ClientRecord;

	vector<stClientRecord> vClientsRecords = GetClientsFromFile();
	while (!FindClientByAccountId(ClientRecord, vClientsRecords, AccountId))
	{
		Printl("The Account ID Doesn't Exist \nPlease Make Sure You Entered The Correct Number");
		AccountId = ReadStringWS(Message);
	}

	UpdateClientRecord(vClientsRecords, ClientRecord);




}
void ShowFindClientScreen() {
	ScreenTitle("Find Client");
	string Message = "Please Enter The Account ID You Want To Find";

	string AccountId = ReadStringWS(Message);
	stClientRecord ClientRecord;

	vector<stClientRecord> vClientsRecords = GetClientsFromFile();
	while (!FindClientByAccountId(ClientRecord, vClientsRecords, AccountId))
	{
		Printl("The Account ID Doesn't Exist \nPlease Make Sure You Entered The Correct Number");
		AccountId = ReadStringWS(Message);
	}

	PrintClientCard(ClientRecord);




}


void GoBackToMainMenu() {
	PrintLine();
	Printl("\t\tPress Any Key To Go Back To Main Menu");
	PrintLine();

	system("pause>0");
	ShowMainMenuScreen();
}

void GoToScreen(enMainMenuScreens Screen) {
	switch (Screen)
	{
	case ClientList:
		system("cls");

		ShowClientListScreen();
		GoBackToMainMenu();
		break;
	case NewClient:
		system("cls");

		ShowNewClientScreen();

		GoBackToMainMenu();
		break;
	case DeleteClient:
		system("cls");

		ShowDeleteClientScreen();

		GoBackToMainMenu();
		break;
	case UpdateClientInfo:
		system("cls");

		ShowUpdateClientScreen();

		GoBackToMainMenu();
		break;
	case FindClient:
		system("cls");

		ShowFindClientScreen();

		GoBackToMainMenu();
		break;
	case Exit:
		system("cls");

		ShowExitScreen();

		break;
	}
}
void ShowMainMenuScreen() {
	system("cls");
	PrintLine("=");

	Printl("\t Main Menu Screen");
	PrintLine("=");
	Printl("\t [1] Show Client List");
	Printl("\t [2] Add New Client");
	Printl("\t [3] Delete Client");
	Printl("\t [4] Update Client Info");
	Printl("\t [5] Find Client");
	Printl("\t [6] Exit");

	PrintLine("=");

	enMainMenuScreens Screen = (enMainMenuScreens)
		ReadNumberInRange("What Do You Want To Do ? \nEnter a Number [1 to 6]", 1, 6);

	GoToScreen(Screen);

}

int main() {

	ShowMainMenuScreen();


	return 0;
}