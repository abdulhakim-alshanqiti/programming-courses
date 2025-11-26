#include <iostream>
#include<iomanip>
#include "../../Libs/MyLib.h"
#include "../../Libs/Date.h"
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
	string GetFirstName() {
		return _FirstName;
	}
	string GetLastName() {
		return _LastName;
	}


	string FullName() {
		return  _FirstName + _Separator + _LastName;
	};

	int ID() {
		return _ID;
	}
	__declspec(property(get= GetFirstName ,put= SetFirstName)) string FirstName;
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

};
int main() {
	SeedRandomness();

	clsPerson Person1;

	Person1.FirstName = "Abdulhakim";
	Person1.LastName = "Alshanqiti";

	Printl("Person 1 First Name : " + Person1.FirstName);
	Printl("Person 1 Last Name  : " + Person1.LastName);

	Printl("Person 1 Full Name  : " + Person1.FullName());
	Printl("Person 1 Id : " + to_string(Person1.ID()) );


	return 0;
}