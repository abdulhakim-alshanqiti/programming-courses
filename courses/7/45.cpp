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
int main() {
	stClientRecord ClientRecord = NewClientRecord();


	cout << ClientRecordToString(ClientRecord) << endl;

	return 0;
}