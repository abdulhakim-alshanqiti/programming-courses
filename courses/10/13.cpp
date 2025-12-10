#include <iostream>
#include "../../libs/MyLib.h"
#include "../../libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsPerson {
private:
	static int _UsersCount;
	int _ID = 0;
	string _FirstName = "";
	string _LastName = "";
	string _Email = "";
	string _Phone = "";
public:


	clsPerson(string FirstName, string LastName, string Email, string Phone) {
		_UsersCount++;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
		_ID = _UsersCount;
	
	}
	string FullName() {
		return _FirstName + " " + _LastName;
	}

	void Print() {
		Printl("--------------------------------------------------------------");
		Printl("ID : " + to_string( _ID) );
		Printl("First Name : " + _FirstName);
		Printl("Last Name : " + _LastName);
		Printl("FullName : " + FullName());
		Printl("Email : " + _Email);
		Printl("Phone : " + _Phone);
		Printl("--------------------------------------------------------------");
	}
	void SendEmail(string Subject, string Body) {
		Printl("Email Has Been Sent to "  + _Email + " With The Following Content");
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

int clsPerson::_UsersCount = 0;

int main() {
	clsPerson Person1("Abdulhakim", "Alshanqiti","example.gmail.com","+9660000000000");
	Person1.Print();

	
	Person1.SendEmail("Greetings","Hey Abdulhakim");
	Person1.SendSMS( "Hey Abdulhakim");
	return 0;

}