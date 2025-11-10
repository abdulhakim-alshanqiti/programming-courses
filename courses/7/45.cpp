//#include <iostream>
//#include<string>
//#include<vector>
//#include "../../Libs/MyLib.h"
//using namespace Input;
//using namespace std;
//using namespace Strings;
//
//struct stCLientRecord {
//	string	AccountNumber = "";
//	string	PinCode = "";
//	string	Name = "";
//	string	Phone = "";
//	double	AccountBalance = 0.0;
//};
//
//stCLientRecord NewClientRecord() {
//	stCLientRecord ClientRecord;
//
//	ClientRecord.AccountNumber = ReadStringWS("Please Enter Your Account Number");
//	ClientRecord.PinCode = ReadStringWS("Please Enter Your Pin Code");
//	ClientRecord.Name = ReadStringWS("Please Enter Your Name");
//	ClientRecord.Phone = ReadStringWS("Please Enter Your Phone Number");
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
//int main() {
//	stCLientRecord ClientRecord = NewClientRecord();
//
//
//	cout << ClientRecordToString(ClientRecord) << endl;
//
//	return 0;
//}