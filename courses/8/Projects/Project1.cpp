#include <string>

#include "../../../Libs/MyLib.h"
#include "../../../Libs/Date.h"
#include<fstream>
#include<iomanip>

using namespace std;
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;

enum MainMenuPerms  {
	AllPerms = -1,
	ViewClientListPerm = 1,
	AddClientPerm = 2,
	DeleteClientPerm = 4,
	UpdateClientPerm = 8,
	FindClientPerm = 16,
	ViewTransactionsPerm = 32,
	ManageUsersPerm = 64
};

struct stUser {
	string Username = "";
	string Password = "";
	short Perms = 0;
	bool MarkForDeletion = false;
};
stUser CurrentUser;





struct stClientRecord {
	string	AccountId = "";
	string	PinCode = "";
	string	Name = "";
	string	Phone = "";
	double	AccountBalance = 0.0;
	bool MarkForDeletion = false;
};
enum enMainMenuScreens {
	ClientListScreen = 1,
	NewClientScreen = 2,
	DeleteClientScreen = 3,
	UpdateClientInfoScreen = 4,
	FindClientScreen = 5,
	TransactionsScreen = 6,
	ManageUsersScreen = 7,
	LogoutScreen = 8,
};

enum enTransactionMenuScreens {
	DepositScreen = 1,
	WithdrawScreen = 2,
	TotalBalancesScreen = 3,
	FromTransactionToMainMenu = 4,
};
enum enManageUsersMenuScreens {
	UserListScreen = 1,
	AddUserScreen = 2,
	DeleteUserScreen = 3,
	UpdateUserScreen = 4,
	FindUserScreen = 5,
	FromManageUsersToMainMenu = 6,
};
const string ClientsFilePath = "./courses/8/Projects/Project1.txt";
const string UsersFilePath = "./courses/8/Projects/Project1Users.txt";
void Login();
void ShowMainMenuScreen();
void ShowTransactionsScreen();
void ShowManageUsersScreen();

void PrintLine(string StringToRepeat = "_") {
	cout << "\n" << RepeatString(92, StringToRepeat) << "\n\n";
}
void ShowAccessDenied() {
	PrintLine("=");
	Printl("\t Access Denied");
	PrintLine("=");
}


bool CheckPerms(MainMenuPerms Permisson) {
	if (Permisson == AllPerms)
		return true;

	if ((CurrentUser.Perms & Permisson) == Permisson) 
		return true;
	
	else 
		return false;
	

}
vector<stUser> GetUsersFromFile();

bool ReadBool(string Message) {
	char Answer = 'y';
	do {
		Answer = ReadChar(Message);
	} while (toupper(Answer) != 'Y' && toupper(Answer) != 'N');

	return    (toupper(Answer) == 'Y') ? true : false;
}

bool FindUserByUsernameAndPassword(stUser& TempUser, vector<stUser>& vUsers, string UsernameToSearchFor, string Password) {



	for (stUser& User : vUsers)
	{
		if (User.Username == UsernameToSearchFor && User.Password == Password)
		{
			TempUser = User;
			return true;
		}
	}


	return false;
}


bool FindUserByUsername(stUser& TempUser, vector<stUser>& vUsers, string UsernameToSearchFor) {



	for (stUser& User : vUsers)
	{
		if (User.Username == UsernameToSearchFor)
		{
			TempUser = User;
			return true;
		}
	}


	return false;
}

bool TryLogin(vector<stUser>& vUsers, string Username, string Password) {



	return FindUserByUsernameAndPassword(CurrentUser,vUsers,Username,Password);
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
bool DoesUserExistByUsername(string Username, vector<stUser>& vUsers) {

	for (stUser& User : vUsers)
	{
		if (User.Username == Username)
		{
			return true;
		}
	}


	return false;
}
string ClientRecordToString(stClientRecord Client, string Seperator = "#//#") {
	string sClientRecord = "";

	sClientRecord += Client.AccountId + Seperator;
	sClientRecord += Client.PinCode + Seperator;
	sClientRecord += Client.Name + Seperator;
	sClientRecord += Client.Phone + Seperator;
	sClientRecord += to_string(Client.AccountBalance);

	return sClientRecord;
}
string UserToString(stUser User, string Seperator = "#//#") {
	string sUser = "";

	sUser += User.Username + Seperator;
	sUser += User.Password + Seperator;
	sUser += to_string(User.Perms);

	return sUser;
}
short ReadPerms( ) {

	bool FullAccess = ReadBool("Do You Want To Give The User Full Access y/n");

	if (FullAccess) {
		return AllPerms ;
	}
	else {

	short Permissions =0;

	if (ReadBool("Do You Want The User to View Client List? y/n"))
		Permissions += ViewClientListPerm;
	if (ReadBool("Do You Want The User to View Transactions? y/n"))
		Permissions += ViewTransactionsPerm;
	if (ReadBool("Do You Want The User to Find Clients ? y/n"))
		Permissions += FindClientPerm;
	if (ReadBool("Do You Want The User to Add Clients ? y/n"))
		Permissions += AddClientPerm;
	if (ReadBool("Do You Want The User to Delete Clients ? y/n"))
		Permissions += DeleteClientPerm;
	if (ReadBool("Do You Want The User to Update Clients ? y/n"))
		Permissions += UpdateClientPerm;
	if (ReadBool("Do You Want The User to Manage Users ? y/n"))
		Permissions += ManageUsersPerm;

	if (Permissions == 127) {
		return AllPerms;
	}

	return Permissions;
	}
}



stClientRecord ClientRecordFromString(string sClientRecord, string Seperator = "#//#") {

	vector<string> vSections = SplitString(sClientRecord, Seperator);
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
string ReadUniqueUsername() {
	vector<stUser> vUsers = GetUsersFromFile();

	string Username = ReadStringWS("Please Enter Your Username");

	while (DoesUserExistByUsername(Username, vUsers))
	{
		Printl("The Username Already Exist \nPlease Choose A Diffirent Username");
		Username = ReadStringWS("Please Enter Your Username");
	}

	return Username;
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

stUser ReadUser(string Username = "") {

	stUser User;
	User.Username = (Username == "") ? ReadUniqueUsername() : Username;
	User.Password = ReadStringWS("Please Enter The Password For This User");

	User.Perms = ReadPerms();



	return User;
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


void PrintUserCard(stUser User) {
	PrintLine();
	cout
		<< "Username :" << User.Username << endl
		<< "Password :" << User.Password << endl
		<< "Perm Number  :" << to_string(User.Perms) << endl;
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
void SaveUsersDataToFile(vector<stUser>& vUsers) {
	fstream MyFile;
	string Line = "";
	MyFile.open(UsersFilePath, ios::out);

	if (MyFile.is_open()) {
		for (stUser& User : vUsers) {
			if (User.MarkForDeletion == false) {
				Line = UserToString(User);
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

void UpdateUser(vector<stUser>& vUsers, stUser& UserToUpdate) {
	char AreYouSure = 'n';
	AreYouSure = ReadChar("Are You Sure You Want To Update This User ?");
	if (toupper(AreYouSure) == 'Y') {

		for (stUser& User : vUsers)
		{
			if (User.Username == UserToUpdate.Username)
			{
				User = ReadUser(User.Username);

				break;
			}
		}

		SaveUsersDataToFile(vUsers);


		Printl("User Updated Succesfully");
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

void DeleteUser(vector<stUser>& vUsers, stUser& UserToDelete) {
	char AreYouSure = 'n';
	AreYouSure = ReadChar("Are You Sure You Want To Delete This User ?");
	if (toupper(AreYouSure) == 'Y') {

		for (stUser& User : vUsers)
		{
			if (User.Username == UserToDelete.Username)
			{
				User.MarkForDeletion = true;

				break;
			}
		}

		SaveUsersDataToFile(vUsers);
		Printl("Record Deleted Succesfully");
	}
}



void AddNewUser() {

	vector<stUser> vUsers = GetUsersFromFile();


	vUsers.push_back(ReadUser());
	SaveUsersDataToFile(vUsers);
}
void AddNewClient() {

	vector<stClientRecord> vClientsRecords = GetClientsFromFile();


	vClientsRecords.push_back(ReadClientRecord());
	SaveClientsDataToFile(vClientsRecords);
}
void ChangeAmmountInAccount(string Message, bool change) {

	string AccountId = ReadStringWS(Message);

	vector<stClientRecord> vClientsRecords = GetClientsFromFile();

	while (!DoesClientExistByAccountId(AccountId, vClientsRecords))
	{
		Printl("The Account ID Doesn't Exist \nPlease Make Sure You Entered The Correct Number");
		AccountId = ReadStringWS(Message);
	}


	for (stClientRecord& ClientRecord : vClientsRecords) {

		if (ClientRecord.AccountId == AccountId) {
			PrintClientCard(ClientRecord);

			double ChangeAmmount = 0;
			if (change) {
				ChangeAmmount = (double)ReadPositiveNumber("Please Enter The Ammount You Want To Deposit");


			}
			else {
				ChangeAmmount = (double)
					ReadNumberInRange("Please Enter The Ammount You Want To WithDraw Must Be Less Than Or Equal To" + to_string(ClientRecord.AccountBalance), 1, ClientRecord.AccountBalance);
				ChangeAmmount *= -1;

			}
			char AreYouSure = 'n';
			AreYouSure = ReadChar("Are You Sure You Want To Perform This Action ?");
			if (toupper(AreYouSure) == 'Y') {

				ClientRecord.AccountBalance = ClientRecord.AccountBalance + ChangeAmmount;
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


void ShowClientListScreen() {


	if (!CheckPerms(ViewClientListPerm)) {
		ShowAccessDenied();
		return;
	}
	vector<stClientRecord> vClientsRecords = GetClientsFromFile();

	PrintAllClientsData(vClientsRecords);

}
void ShowNewUserScreen() {

	ScreenTitle("Add New User");

	char AddMore = 'Y';

	while (toupper(AddMore) == 'Y')
	{
		system("cls");
		AddNewUser();
		AddMore = ReadChar("User Added Successfully \nDo You Want To Add More Clients?");

	}

}

void ShowNewClientScreen() {
	if (!CheckPerms(AddClientPerm)) {
		ShowAccessDenied();
		return;
	}

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
	if (!CheckPerms(DeleteClientPerm)) {
		ShowAccessDenied();
		return;
	}
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
void ShowDeleteUserScreen() {

	ScreenTitle("Delete User");
	string Message = "Please Enter The Username For The User You Want To Delete";

	string Username = ReadStringWS(Message);
	stUser User;

	vector<stUser> vUsers = GetUsersFromFile();
	while (!FindUserByUsername(User, vUsers, Username))
	{
		Printl("The Username Doesn't Exist \nPlease Make Sure You Entered The Correct Username");
		Username = ReadStringWS(Message);
	}

	DeleteUser(vUsers, User);




}
void ShowUpdateClientScreen() {
	if (!CheckPerms(UpdateClientPerm)) {
		ShowAccessDenied();
		return;
	}

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

	PrintClientCard(ClientRecord);
	UpdateClientRecord(vClientsRecords, ClientRecord);




}

void ShowUpdateUserScreen() {
	ScreenTitle("Update User");
	string Message = "Please Enter The Username For The User You Want To Update";

	string Username = ReadStringWS(Message);
	stUser User;

	vector<stUser> vUsers = GetUsersFromFile();
	while (!FindUserByUsername(User, vUsers, Username))
	{
		Printl("The Username Doesn't Exist \nPlease Make Sure You Entered The Correct Username");
		Username = ReadStringWS(Message);
	}

	PrintUserCard(User);

	UpdateUser(vUsers, User);




}


void ShowFindClientScreen() {
	if (!CheckPerms(FindClientPerm)) {
		ShowAccessDenied();
		return;
	}
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

void ShowFindUserScreen() {
	ScreenTitle("Find User");
	string Message = "Please Enter The Username You Want To Find";

	string Username = ReadStringWS(Message);
	stUser User;

	vector<stUser> vUsers = GetUsersFromFile();
	while (!FindUserByUsername(User, vUsers, Username))
	{
		Printl("The Username Doesn't Exist \nPlease Make Sure You Entered The Correct Username");
		Username = ReadStringWS(Message);
	}

	PrintUserCard(User);




}

void ShowDepositScreen() {

	ScreenTitle("Deposit");
	string Message = "Please Enter The Account ID You Want To Deposit To";
	ChangeAmmountInAccount(Message, true);


}

void ShowWithDrawScreen() {
	ScreenTitle("WithDraw");
	string Message = "Please Enter The Account ID You Want To WithDraw From";
	ChangeAmmountInAccount(Message, false);

}

void ShowTotalBalancesScreen() {
	ScreenTitle("Total Balances");

	cout
		<< " | " << left << setw(15) << "Account ID"
		<< " | " << left << setw(22) << "Name"
		<< " | " << left << setw(22) << "Balance" <<
		endl;

	PrintLine();
	double TotalBalances = 0.0;
	vector<stClientRecord> vClientsRecords = GetClientsFromFile();

	if (vClientsRecords.size() == 0)
		Printl("\t\t\t\tNo Clients Are Available In The System !!");

	else {
		for (stClientRecord& ClientRecord : vClientsRecords) {
			TotalBalances += ClientRecord.AccountBalance;

			cout
				<< " | " << left << setw(15) << ClientRecord.AccountId
				<< " | " << left << setw(22) << ClientRecord.Name
				<< " | " << left << setw(22) << to_string(ClientRecord.AccountBalance) <<
				endl;



		}
	}


	PrintLine();
	Printl("Total Balances : " + to_string(TotalBalances));
}

void GoBackToMainMenu() {
	PrintLine();
	Printl("\t\tPress Any Key To Go Back To Main Menu");
	PrintLine();

	system("pause>0");
	ShowMainMenuScreen();
}

void GoBackToTransactionsMenu() {
	PrintLine();
	Printl("\t\tPress Any Key To Go Back To Transactions Menu");
	PrintLine();

	system("pause>0");
	ShowTransactionsScreen();
}


void ShowListUsersScreen() {
	vector<stUser> vUsers = GetUsersFromFile();
	ScreenTitle("Users List (" + to_string(vUsers.size()) + ") Users" );

	cout
		<< " | " << left << setw(15) << "Username"
		<< " | " << left << setw(22) << "Password"
		<< " | " << left << setw(22) << "Perms" <<
		endl;

	PrintLine();


	if (vUsers.size() == 0)
		Printl("\t\t\t\tNo Users Are Available In The System !!");

	else {
		for (stUser& User : vUsers) {

			cout
				<< " | " << left << setw(15) << User.Username
				<< " | " << left << setw(22) << User.Password
				<< " | " << left << setw(22) << to_string(User.Perms) <<
				endl;



		}
	}


	PrintLine();

}
void GoBackToManageUsersMenu() {
	PrintLine();
	Printl("\t\tPress Any Key To Go Back To Manage Users Menu");
	PrintLine();

	system("pause>0");
	ShowManageUsersScreen();
}

void GoToSubManageUsersScreens( enManageUsersMenuScreens Screen) {
	switch (Screen)
	{
	case UserListScreen:
		system("cls");
		ShowListUsersScreen();
		GoBackToManageUsersMenu();
		break;

	case AddUserScreen:
		system("cls");
		ShowNewUserScreen();
		GoBackToManageUsersMenu();
		break;
	case DeleteUserScreen:
		system("cls");
		ShowDeleteUserScreen();
		GoBackToManageUsersMenu();
		break;
	case UpdateUserScreen:
		system("cls");
		ShowUpdateUserScreen();
		GoBackToManageUsersMenu();
		break;
	case FindUserScreen:
		system("cls");
		ShowFindUserScreen();
		GoBackToManageUsersMenu();
		break;
	case FromManageUsersToMainMenu:
		ShowMainMenuScreen();
		break;

	}

}

void GoToSubTransactionScreens(enTransactionMenuScreens Screen) {
	switch (Screen)
	{
	case DepositScreen:
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionsMenu();
		break;

	case WithdrawScreen:
		system("cls");
		ShowWithDrawScreen();
		GoBackToTransactionsMenu();
		break;
	case TotalBalancesScreen:
		system("cls");
		ShowTotalBalancesScreen();
		GoBackToTransactionsMenu();
		break;
	case FromTransactionToMainMenu:
		GoBackToMainMenu();
		break;

	}

}


void GoToMainMenuScreens( enMainMenuScreens Screen) {
	switch (Screen)
	{
	case ClientListScreen:
		system("cls");
	 
		ShowClientListScreen();

	
		GoBackToMainMenu();
		break;
	case NewClientScreen:
		system("cls");


		ShowNewClientScreen();


		GoBackToMainMenu();
		break;
	case DeleteClientScreen:
		system("cls");

		 ShowDeleteClientScreen() ;

		GoBackToMainMenu();
		break;
	case UpdateClientInfoScreen:
		system("cls");

	 ShowUpdateClientScreen() ;

		GoBackToMainMenu();
		break;
	case FindClientScreen:
		system("cls");

		ShowFindClientScreen();

		GoBackToMainMenu();
		break;

	case TransactionsScreen:
		system("cls");

	 ShowTransactionsScreen();
	 
	 GoBackToMainMenu();
		break;

	case ManageUsersScreen:
		system("cls");

		ShowManageUsersScreen();

	 GoBackToMainMenu();
		break;
	case LogoutScreen:
		system("cls");

		Login();

		break;
	}
}

void ShowManageUsersScreen() {
	if (!CheckPerms(ManageUsersPerm)) {
		ShowAccessDenied();
		return;
	}
	system("cls");
	PrintLine("=");

	Printl("\t Manage Users Menu Screen");
	PrintLine("=");
	Printl("\t [1] List Users");
	Printl("\t [2] Add New User");
	Printl("\t [3] Delete User");
	Printl("\t [4] Update User");
	Printl("\t [5] Find User");
	Printl("\t [6] Main Menu");
	PrintLine("=");


	enManageUsersMenuScreens Screen = (enManageUsersMenuScreens)
		ReadNumberInRange("What Do You Want To Do ? \nEnter a Number [1 to 6]", 1, 6);

	GoToSubManageUsersScreens(Screen);
}
void ShowTransactionsScreen() {
	if (!CheckPerms(ViewTransactionsPerm)) {
		ShowAccessDenied();
		return;
	}

	system("cls");
	PrintLine("=");

	Printl("\t Transaction Menu Screen");
	PrintLine("=");
	Printl("\t [1] Deposit");
	Printl("\t [2] Withdraw");
	Printl("\t [3] Total Balances");
	Printl("\t [4] Go Back To Main Menu");
	PrintLine("=");


	enTransactionMenuScreens Screen = (enTransactionMenuScreens)
		ReadNumberInRange("What Do You Want To Do ? \nEnter a Number [1 to 4]", 1, 4);

	GoToSubTransactionScreens(Screen);

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
	Printl("\t [6] Transactions");
	Printl("\t [7] Manage Users");
	Printl("\t [8] Logout");

	PrintLine("=");

	enMainMenuScreens Screen = (enMainMenuScreens)
		ReadNumberInRange("What Do You Want To Do ? \nEnter a Number [1 to 8]", 1, 8);

	GoToMainMenuScreens(Screen);

}



stUser UserFromString(string sUser, string Seperator = "#//#") {

	vector<string> vSections = SplitString(sUser, Seperator);
	stUser User;

	User.Username = vSections[0];
	User.Password = vSections[1];

	short UserPerms = stoi(vSections[2]);
	User.Perms = UserPerms;

	return User;
}
vector<stUser> GetUsersFromFile() {
	vector<stUser> vUsers;

	fstream MyFile;

	string line = "";
	stUser User;

	MyFile.open(UsersFilePath, ios::in);

	if (MyFile.is_open()) {
		while (getline(MyFile, line)) {

			User = UserFromString(line);
			vUsers.push_back(User);
		}
	}

	MyFile.close();

	return vUsers;
}
void Login() {


	vector<stUser> vUsers = GetUsersFromFile();
	bool LoginFailed = false;
	do {
		system("cls");
		PrintLine("=");
		Printl("\t Login Screen");
		PrintLine("=");

		if (LoginFailed) 
			Printl("Invalid Username/Password");
		
	string Username= ReadStringWS("Enter Your Username");
	string Password = ReadStringWS("Enter Your Password");

	LoginFailed = !TryLogin(vUsers, Username, Password);

	}
   while (LoginFailed);

	ShowMainMenuScreen();

}

int main() {


	Login();


	return 0;
}