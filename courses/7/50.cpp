//#include <iostream>
//#include<string>
//#include<vector>
//#include<fstream>
//#include<iomanip>
//#include "../../Libs/MyLib.h"
//using namespace Input;
//using namespace std;
//using namespace Strings;
//using namespace Output;
//struct stCLientRecord {
//	string	AccountNumber = "";
//	string	PinCode = "";
//	string	Name = "";
//	string	Phone = "";
//	double	AccountBalance = 0.0;
//	bool MarkForDeletion = false;
//};
//
//const string ClientsFilePath = "./courses/7/files/50.txt";
//
//
//void AddClientRecordToFile(string ClientRecord) {
//	fstream MyFile;
//
//	MyFile.open(ClientsFilePath, ios::out | ios::app);
//
//
//
//	if (MyFile.is_open()) {
//
//		MyFile << ClientRecord << endl;
//
//	}
//	MyFile.close();
//}
//
//stCLientRecord NewClientRecord() {
//	stCLientRecord ClientRecord;
//
//	ClientRecord.AccountNumber = ReadStringWS("Please Enter Your Account Number");
//	ClientRecord.PinCode = ReadString("Please Enter Your Pin Code");
//	ClientRecord.Name = ReadString("Please Enter Your Name");
//	ClientRecord.Phone = ReadString("Please Enter Your Phone Number");
//	ClientRecord.AccountBalance = ReadPositiveDouble("Please Enter Your Account Balance");
//
//	return ClientRecord;
//}
//string ClientRecordToString(stCLientRecord Client, string Seperator = "#//#") {
//	string sClientRecord = "";
//
//	sClientRecord += Client.AccountNumber + Seperator;
//	sClientRecord += Client.PinCode + Seperator;
//	sClientRecord += Client.Name + Seperator;
//	sClientRecord += Client.Phone + Seperator;
//	sClientRecord += to_string(Client.AccountBalance);
//
//	return sClientRecord;
//}
//
//stCLientRecord ClientRecordFromString(string sClientRecord, string Seperator = "#//#") {
//
//	vector<string> vSections = SplitString(sClientRecord, Seperator);
//	stCLientRecord ClientRecord;
//
//	ClientRecord.AccountNumber = vSections[0];
//	ClientRecord.PinCode = vSections[1];
//	ClientRecord.Name = vSections[2];
//	ClientRecord.Phone = vSections[3];
//	ClientRecord.AccountBalance = stod(vSections[4]);
//	ClientRecord.MarkForDeletion = false;
//
//	return ClientRecord;
//}
//
//void PrintClientCard(stCLientRecord ClientRecord) {
//
//	cout
//		<< "Account Number :" << ClientRecord.AccountNumber << endl
//		<< "Pin Code :" << ClientRecord.PinCode << endl
//		<< "Name :" << ClientRecord.Name << endl
//		<< "Phone :" << ClientRecord.Phone << endl
//		<< "Account Balance  :" << ClientRecord.AccountBalance << endl;
//
//}
//
//
//
//vector<stCLientRecord> GetClientsFromFile(string ClientsFilePath) {
//	vector<stCLientRecord> vClientRecords;
//
//	fstream MyFile;
//
//	string line = "";
//	stCLientRecord ClientRecord;
//
//	MyFile.open(ClientsFilePath, ios::in);
//
//	if (MyFile.is_open()) {
//		while (getline(MyFile, line)) {
//
//			ClientRecord = ClientRecordFromString(line);
//			vClientRecords.push_back(ClientRecord);
//		}
//	}
//
//	MyFile.close();
//
//	return vClientRecords;
//}
//
//void PrintLine() {
//	cout << "\n" << RepeatString(92, "_") << "\n\n";
//}
//void PrintColumnsNames() {
//	cout
//		<< " | " << left << setw(15) << "Account Number"
//		<< " | " << left << setw(10) << "PinCode"
//		<< " | " << left << setw(20) << "Name"
//		<< " | " << left << setw(15) << "Phone"
//		<< " | " << left << setw(10) << "Balance";
//}
//void PrintTableHead() {
//	PrintLine();
//	PrintColumnsNames();
//	PrintLine();
//}
//void PrintTableBody(vector<stCLientRecord>& vClientsRecords) {
//
//	for (stCLientRecord& CLientRecord : vClientsRecords) {
//		PrintClientCard(CLientRecord);
//	}
//	PrintLine();
//}
//void PrintAllClientsData() {
//	vector<stCLientRecord> vClientsRecords = GetClientsFromFile(ClientsFilePath);
//	cout << "\t\t\t\t" << "Client List (" << vClientsRecords.size() << ") Client(s)." << endl;
//
//	PrintTableHead();
//	PrintTableBody(vClientsRecords);
//}
//
//
//
//stCLientRecord FindClientByAccountNumber(vector<stCLientRecord>& vClientsRecords, string AccountNumberToSearchFor) {
//
//	for (stCLientRecord& ClientRecord : vClientsRecords)
//	{
//		if (ClientRecord.AccountNumber == AccountNumberToSearchFor)
//		{
//			return ClientRecord;
//		}
//	}
//
//	stCLientRecord EmptyClientRecord;
//	return EmptyClientRecord;
//}
//void SaveClientsDataToFile(vector<stCLientRecord>& vClientsRecords) {
//	fstream MyFile;
//	string Line = "";
//	MyFile.open(ClientsFilePath, ios::out);
//
//	if (MyFile.is_open()) {
//		for (stCLientRecord& ClientRecord : vClientsRecords) {
//			if (ClientRecord.MarkForDeletion == false) {
//				Line = ClientRecordToString(ClientRecord);
//				MyFile << Line << endl;
//			}
//
//
//
//		}
//	}
//	MyFile.close();
//}
//
//void MarkClientRecordForDeletion(vector<stCLientRecord>& vClientsRecords, stCLientRecord& ClientRecordToDelete) {
//	char AreYouSure = 'n';
//	AreYouSure = ReadChar("Are You Sure You Want To Delete Record ?");
//	if (toupper(AreYouSure) == 'Y') {
//
//		for (stCLientRecord& ClientRecord : vClientsRecords)
//		{
//			if (ClientRecord.AccountNumber == ClientRecordToDelete.AccountNumber)
//			{
//				ClientRecord.MarkForDeletion = true;
//			}
//		}
//
//		SaveClientsDataToFile(vClientsRecords);
//		vClientsRecords = GetClientsFromFile(ClientsFilePath);// Refresh Vector
//
//		Printl("Record Deleted Succesfully");
//	}
//}
//int main() {
//
//	string AccountNumberToSearchFor = ReadStringWS("What Is The Account Number You Want To Delete?");
//	vector<stCLientRecord> vClientsRecords = GetClientsFromFile(ClientsFilePath);
//
//	stCLientRecord ClientRecord = FindClientByAccountNumber(vClientsRecords, AccountNumberToSearchFor);
//
//	if (ClientRecord.AccountNumber != "")
//	{
//		PrintClientCard(ClientRecord);
//
//
//		MarkClientRecordForDeletion(vClientsRecords, ClientRecord);
//	}
//	else
//		cout << "The Account With Number (" << AccountNumberToSearchFor << ") Doesn't exist" << endl;
//
//
//	return 0;
//}