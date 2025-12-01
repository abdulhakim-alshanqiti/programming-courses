#include <iostream>
#include "../../Libs/MyLib.h"
#include "../../Libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsPerson {
private:
	int _ID = 0;
	string _FirstName = "";
	string _LastName = "";
	string _Email = "";
	string _Phone = "";
public:


	clsPerson(int ID, string FirstName, string LastName, string Email, string Phone) {
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;

	}
	string FullName() {
		return _FirstName + " " + _LastName;
	}

	void Print() {
		Printl("--------------------------------------------------------------");
		Printl("ID : " + to_string(_ID));
		Printl("First Name : " + _FirstName);
		Printl("Last Name : " + _LastName);
		Printl("FullName : " + FullName());
		Printl("Email : " + _Email);
		Printl("Phone : " + _Phone);
		Printl("--------------------------------------------------------------");
	}
	void SendEmail(string Subject, string Body) {
		Printl("Email Has Been Sent to " + _Email + " With The Following Content");
		Printl("Subject: " + Subject);
		Printl("Body: " + Body);
	}


	void SendSMS(string Content) {
		Printl("SMS Has Been Sent to " + _Phone + " With The Following Content");
		Printl(Content);
	}

	int ID() {
		return _ID;
	}

	string GetFirstName() {
		return _FirstName;
	}

	void SetFirstName(string NewName) {
		_FirstName = NewName;
	}

	string GetLastName() {
		return _LastName;
	}

	void SetLastName(string NewName) {
		_LastName = NewName;
	}

	string GetEmail() {
		return _Email;
	}

	void SetEmail(string NewEmail) {
		_Email = NewEmail;
	}



	string GetPhone() {
		return _Phone;
	}

	void SetPhone(string NewPhone) {
		_Phone = NewPhone;
	}

};


class clsEmployee : public clsPerson {

private:
	string _Title = "";
	string _Department = "";
	float _Salary = 0;

public:
	clsEmployee(int ID, string FirstName, string LastName,string Title,string Department,float Salary, string Email, string Phone) 
	: clsPerson( ID, FirstName, LastName, Email, Phone)
	{
		_Title = Title;
		_Department = Department;
		_Salary = Salary;

	}
	string GetTitle() {
		return _Title;
	}

	void SetTitle(string NewTitle) {
		_Title = NewTitle;
	}

	string GetDepartment() {
		return _Department;
	}

	void SetDepartment(string NewDepartment) {
		_Department = NewDepartment;
	}

	float GetSalary() {
		return _Salary;
	}

	void SetSalary(float NewSalary) {
		_Salary = NewSalary;
	}
};


int main() {
	clsEmployee Employee1(1,"Abdulhakim", "Alshanqiti","Software Enginner","Tech Department",12500, "example.gmail.com", "+9660000000000");

	Employee1.Print();
	Printl("Title : " + Employee1.GetTitle());
	Printl("Department : " + Employee1.GetDepartment());
	Printl("Salary : " + to_string(Employee1.GetSalary()));

	return 0;

}