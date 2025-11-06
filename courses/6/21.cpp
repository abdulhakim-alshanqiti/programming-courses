//#include<iostream>
//#include<vector>
//#include<string>
//#include"../../Libs/NumbersLib.h"  
//
//using namespace std;
//using namespace Output;
//using namespace Input;
//
//
//struct stEmployee
//{
//	string FirstName = "";
//	string LastName = "";
//	int Sallary = 0;
//};
//
//
//void ReadEmployees(vector <stEmployee>& vEmployee) {
//	stEmployee tempEmployee;
//	char ReadMore = 'Y';
//	while (ReadMore == 'Y' || ReadMore == 'y') {
//		system("cls");
//
//		tempEmployee.FirstName = ReadString("Please Enter Employee First Name");
//		tempEmployee.LastName = ReadString("Please Enter Employee Last Name");
//		tempEmployee.Sallary = ReadNumber("Please Enter Employee Sallary");
//
//
//		vEmployee.push_back(tempEmployee);
//
//
//		ReadMore = ReadChar("Do You Want To Add Another Employee? Y/N");
//
//
//	};
//}
//void PrintEmployees(vector <stEmployee>& vEmployee) {
//	for (stEmployee& Employee : vEmployee)
//	{
//		Printl("First Name: " + Employee.FirstName);
//		Printl("Last Name: " + Employee.LastName);
//		Printl("Sallary: " + to_string(Employee.Sallary));
//		Printl();
//	}
//}
//int main() {
//	vector <stEmployee> vEmployee;
//
//
//	ReadEmployees(vEmployee);
//	PrintEmployees(vEmployee);
//
//	return 0;
//}