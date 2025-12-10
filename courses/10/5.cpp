#include <iostream>
#include<iomanip>
#include "../../libs/MyLib.h"
#include "../../libs/Date.h"
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsPerson {
private:

	string _FirstName = "";
	string _LastName = "";
	string _Separator = " ";
	int _ID = RandomNumber(1, 100); // This is a ReadOnly Property Because we don't have a set method
public:

	void SetFirstName(string NewName) {
		_FirstName = NewName;
	}
	void SetLastName(string NewName) {
		_LastName = NewName;
	}
	string FirstName() {
		return _FirstName;
	}
	string LastName() {
		return _LastName;
	}


	string FullName() {
		return  _FirstName + _Separator + _LastName;
	};

	int ID() {
		return _ID;
	}


};
int main() {
	SeedRandomness();

	clsPerson Person1;

	Person1.SetFirstName("Abdulhakim");
	Person1.SetLastName("Alshanqiti");

	Printl("Person 1 First Name :" + Person1.FirstName());
	Printl("Person 1 Last Name :" + Person1.LastName());

	Printl("Person 1 Full Name :" + Person1.FullName());
	Printl("Person 1 Id :" + to_string(Person1.ID()));


	clsPerson Person2;

	Person2.SetFirstName("Kemo");
	Person2.SetLastName("Nas");

	Printl("Person 2 First Name :" + Person2.FirstName());
	Printl("Person 2 Last Name :" + Person2.LastName());

	Printl("Person 2 Full Name :" + Person2.FullName());
	Printl("Person 2 ID :" + to_string(Person2.ID()));


	return 0;
}