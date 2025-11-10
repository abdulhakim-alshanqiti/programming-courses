//#include <iostream>
//#include<string>
//#include<vector>
//#include<fstream>
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
//
//void AddClientRecordToFile(string ClientRecord, string filePath) {
//	fstream MyFile;
//
//	MyFile.open(filePath, ios::out | ios::app);
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
//	vector<string> vSections = SplitString(sClientRecord, Seperator);
//	stCLientRecord ClientRecord;
//
//	ClientRecord.AccountNumber = vSections[0];
//	ClientRecord.PinCode = vSections[1];
//	ClientRecord.Name = vSections[2];
//	ClientRecord.Phone = vSections[3];
//	ClientRecord.AccountBalance = stod(vSections[4]);
//
//	return ClientRecord;
//}
//
//void PrintClientRecord(stCLientRecord ClientRecord) {
//
//
//	cout << "Client AccountNumber : " << ClientRecord.AccountNumber << endl;
//	cout << "Client PinCode : " << ClientRecord.PinCode << endl;
//	cout << "Client Name : " << ClientRecord.Name << endl;
//	cout << "Client Phone : " << ClientRecord.Phone << endl;
//	cout << "Client AccountBalance : " << ClientRecord.AccountBalance << endl;
//
//}
//void AddClients() {
//	char AddMore = 'Y';
//	do {
//		system("cls");
//		printf("Add New Client:\n");
//
//		stCLientRecord ClientRecord = NewClientRecord();
//		PrintClientRecord(ClientRecord);
//		string sClientRecord = ClientRecordToString(ClientRecord);
//		cout << sClientRecord << endl;
//		AddClientRecordToFile(sClientRecord, "./courses/7/files/47.txt");
//
//		printf("Client Added Successfully \n");
//		AddMore = ReadChar("Do You Want To Add More CLients ?\n");
//
//	} while (toupper(AddMore) == 'Y');
//
//
//}
//int main() {
//	AddClients();
//
//	return 0;
//}