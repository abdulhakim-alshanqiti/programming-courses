#include <iostream>
#include "../../libs/MyLib.h"
#include "../../libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsPerson {
protected:
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

	string FirstName() {
		return _FirstName;
	}

	void SetFirstName(string NewName) {
		_FirstName = NewName;
	}

	string LastName() {
		return _LastName;
	}

	void SetLastName(string NewName) {
		_LastName = NewName;
	}

	string Email() {
		return _Email;
	}

	void SetEmail(string NewEmail) {
		_Email = NewEmail;
	}



	string Phone() {
		return _Phone;
	}

	void SetPhone(string NewPhone) {
		_Phone = NewPhone;
	}

};


class clsEmployee : public clsPerson {

protected:
	string _Title = "";
	string _Department = "";
	float _Salary = 0;

public:
	clsEmployee(int ID, string FirstName, string LastName, string Title, string Department, float Salary, string Email, string Phone)
		: clsPerson(ID, FirstName, LastName, Email, Phone)
	{
		_Title = Title;
		_Department = Department;
		_Salary = Salary;

	}
	void Print() {
		Printl("--------------------------------------------------------------");
		Printl("ID         : " + to_string(_ID ));
		Printl("Salary     : " + to_string(_Salary));
		Printl("Department : " + _Department);
		Printl("Title      : " + _Title);
		Printl("First Name : " + _FirstName);
		Printl("Last Name  : " + _LastName);
		Printl("FullName   : " + FullName());
		Printl("Email      : " + _Email);
		Printl("Phone      : " + _Phone);
		Printl("--------------------------------------------------------------");
	}
	string Title() {
		return _Title;
	}

	void SetTitle(string NewTitle) {
		_Title = NewTitle;
	}

	string Department() {
		return _Department;
	}

	void SetDepartment(string NewDepartment) {
		_Department = NewDepartment;
	}

	float Salary() {
		return _Salary;
	}

	void SetSalary(float NewSalary) {
		_Salary = NewSalary;
	}
};


class clsDeveloper : public clsEmployee {
private:
	string _ProgrammingLanguages = "";
public:

	clsDeveloper(int ID, string FirstName, string LastName, string Title, string Department, float Salary, string Email, string Phone, string ProgrammingLanguages)
		: clsEmployee(ID, FirstName, LastName, Title, Department, Salary, Email, Phone)
	{
		_ProgrammingLanguages = ProgrammingLanguages;
	}
	string ProgrammingLanguages() {
		return _ProgrammingLanguages;
	}

	void SetProgrammingLanguages(string ProgrammingLanguages) {
		_ProgrammingLanguages = ProgrammingLanguages;
	}


	void Print() {
		Printl("--------------------------------------------------------------");
		Printl("ID         : " + to_string(_ID));
		Printl("Salary     : " + to_string(_Salary));
		Printl("Department : " + _Department);
		Printl("Title      : " + _Title);
		Printl("First Name : " + _FirstName);
		Printl("Last Name  : " + _LastName);
		Printl("FullName   : " + FullName());
		Printl("Email      : " + _Email);
		Printl("Phone      : " + _Phone);
		Printl("Programming Languages : " + _ProgrammingLanguages);

		Printl("--------------------------------------------------------------");
	}
};

int main() {
	clsDeveloper Developer(1, "Abdulhakim", "Alshanqiti", "Software Enginner", "Tech Department", 12500, "example.gmail.com", "+9660000000000", "C#,C++,Js");

	Developer.Print();


	return 0;

}