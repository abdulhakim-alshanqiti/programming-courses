#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include "../../Libs/MyLib.h"
using namespace Input;
using namespace std;
using namespace Strings;

struct stClientRecord {
	string	AccountNumber = "";
	string	PinCode = "";
	string	Name = "";
	string	Phone = "";
	double	AccountBalance = 0.0;
};


void AddClientRecordToFile(string ClientRecord, string filePath) {
	fstream MyFile;

	MyFile.open(filePath, ios::out | ios::app);



	if (MyFile.is_open()) {

		MyFile << ClientRecord << endl;

	}
	MyFile.close();
}
stClientRecord NewClientRecord() {
	stClientRecord ClientRecord;

	ClientRecord.AccountNumber = ReadStringWS("Please Enter Your Account Number");
	ClientRecord.PinCode = ReadString("Please Enter Your Pin Code");
	ClientRecord.Name = ReadString("Please Enter Your Name");
	ClientRecord.Phone = ReadString("Please Enter Your Phone Number");
	ClientRecord.AccountBalance = ReadPositiveDouble("Please Enter Your Account Balance");

	return ClientRecord;
}
string ClientRecordToString(stClientRecord Client, string Separator = "#//#") {
	string sClientRecord = "";

	sClientRecord += Client.AccountNumber + Separator;
	sClientRecord += Client.PinCode + Separator;
	sClientRecord += Client.Name + Separator;
	sClientRecord += Client.Phone + Separator;
	sClientRecord += to_string(Client.AccountBalance);

	return sClientRecord;
}

stClientRecord ClientRecordFromString(string sClientRecord, string Separator = "#//#") {
	vector<string> vSections = SplitString(sClientRecord, Separator);
	stClientRecord ClientRecord;

	ClientRecord.AccountNumber = vSections[0];
	ClientRecord.PinCode = vSections[1];
	ClientRecord.Name = vSections[2];
	ClientRecord.Phone = vSections[3];
	ClientRecord.AccountBalance = stod(vSections[4]);

	return ClientRecord;
}

void PrintClientRecord(stClientRecord ClientRecord) {

	cout
		<< " | " << left << setw(15) << ClientRecord.AccountNumber
		<< " | " << left << setw(10) << ClientRecord.PinCode
		<< " | " << left << setw(20) << ClientRecord.Name
		<< " | " << left << setw(15) << ClientRecord.Phone
		<< " | " << left << setw(10) << ClientRecord.AccountBalance << endl;

}


vector<stClientRecord> GetClientsFromFile(string filePath) {
	vector<stClientRecord> vClientRecords;

	fstream MyFile;

	string line = "";
	stClientRecord ClientRecord;

	MyFile.open(filePath, ios::in);

	if (MyFile.is_open()) {
		while (getline(MyFile, line)) {

			ClientRecord = ClientRecordFromString(line);
			vClientRecords.push_back(ClientRecord);
		}
	}

	MyFile.close();

	return vClientRecords;
}
string RepeatString(int length, string StringToRepeat) {
	string Line;
	for (short i = 0; i < length; i++)
	{
		Line += StringToRepeat;
	}
	return Line;
}
void PrintLine() {
	cout << "\n" << RepeatString(92, "_") << "\n\n";
}
void PrintColumnsNames() {
	cout
		<< " | " << left << setw(15) << "Account Number"
		<< " | " << left << setw(10) << "PinCode"
		<< " | " << left << setw(20) << "Name"
		<< " | " << left << setw(15) << "Phone"
		<< " | " << left << setw(10) << "Balance";
}
void PrintTableHead() {
	PrintLine();
	PrintColumnsNames();
	PrintLine();
}
void PrintTableBody(vector<stClientRecord>& ClientsRecords) {


	for (stClientRecord& CLientRecord : ClientsRecords) {
		PrintClientRecord(CLientRecord);
	}
	PrintLine();
}
void PrintAllClientsData(string FilePath) {
	vector<stClientRecord> ClientsRecords = GetClientsFromFile(FilePath);
	cout << "\t\t\t\t" << "Client List (" << ClientsRecords.size() << ") Client(s)." << endl;

	PrintTableHead();
	PrintTableBody(ClientsRecords);
}
int main() {

	PrintAllClientsData("./courses/7/files/48.txt");

	return 0;
}