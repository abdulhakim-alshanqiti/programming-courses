#pragma once

#include <iostream>
#include "./MyLib.h"
#include "./clsPerson.h"

using namespace std;



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
		Printl("ID         : " + to_string(_ID));
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

