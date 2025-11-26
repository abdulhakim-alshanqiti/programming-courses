#include <iostream>
#include<iomanip>
#include "../../Libs/MyLib.h"
#include "../../Libs/Date.h"
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsEmployee {
private:

	string _FirstName = "";
	string _LastName = "";
	string _Separator = " ";
	float _Salary = 0.f;
	int _ID = RandomNumber(1, 100); // This is a ReadOnly Property Because we don't have a set method
public:
	int ID() {
		return _ID;
	}

	float Salary() {
		return _Salary;
	}
	void SetSalary(float Salary) {
		_Salary = Salary;
	}
	string FirstName() {
		return _FirstName;
	}

	void SetFirstName(string Name) {
		_FirstName = Name;
	}
	string LastName() {
		return _LastName;
	}
	void SetLastName(string Name) {
		_LastName = Name;
	}

	string FullName() {
		return  _FirstName + _Separator + _LastName;
	};



};
int main() {
	SeedRandomness();

	clsEmployee Employee1;

	Employee1.SetFirstName("Abdulhakim");
	Employee1.SetLastName("Alshanqiti");
	Employee1.SetSalary(203.5);

	Printl("Employee 1 First Name :" + Employee1.FirstName());
	Printl("Employee 1 Last Name :" + Employee1.LastName());

	Printl("Employee 1 Full Name :" + Employee1.FullName());
	Printl("Employee 1 Id :" + to_string(Employee1.ID()));
	Printl("Employee 1 Salary :" + to_string(Employee1.Salary()));

	Printl(RepeatString(20, "="));
	clsEmployee Employee2;

	Employee2.SetFirstName("Kemo");
	Employee2.SetLastName("Nas");
	Employee2.SetSalary(83.45);

	Printl("Employee 2 First Name :" + Employee2.FirstName());
	Printl("Employee 2 Last Name :" + Employee2.LastName());

	Printl("Employee 2 Full Name :" + Employee2.FullName());
	Printl("Employee 2 ID :" + to_string(Employee2.ID()));
	Printl("Employee 2 Salary :" + to_string(Employee2.Salary()));

	return 0;
}