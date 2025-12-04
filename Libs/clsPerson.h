#pragma once
#include <iostream>
using namespace std;
#include "./MyLib.h"
using namespace Output;

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
