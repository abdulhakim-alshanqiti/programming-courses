#include <iostream>
#include<string>
#include<vector>
#include "../../libs/MyLib.h"
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

stClientRecord NewClientRecord() {
	stClientRecord ClientRecord;

	ClientRecord.AccountNumber = ReadStringWS("Please Enter Your Account Number");
	ClientRecord.PinCode = ReadStringWS("Please Enter Your Pin Code");
	ClientRecord.Name = ReadStringWS("Please Enter Your Name");
	ClientRecord.Phone = ReadStringWS("Please Enter Your Phone Number");
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


	cout << "ClientRecord.AccountNumber = " << ClientRecord.AccountNumber << endl;
	cout << "ClientRecord.PinCode = " << ClientRecord.PinCode << endl;
	cout << "ClientRecord.Name = " << ClientRecord.Name << endl;
	cout << "ClientRecord.Phone = " << ClientRecord.Phone << endl;
	cout << "ClientRecord.AccountBalance = " << ClientRecord.AccountBalance << endl;

}
int main() {
	stClientRecord ClientRecord = NewClientRecord();
	PrintClientRecord(ClientRecord);

	string sClientRecord = ClientRecordToString(ClientRecord);
	cout << sClientRecord << endl;

	PrintClientRecord(ClientRecordFromString(sClientRecord));


	return 0;
}