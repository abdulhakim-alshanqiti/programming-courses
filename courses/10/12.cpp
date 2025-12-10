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
	static short _Counter;
	string _Name = "";
public:
	static short GetPeopleCount() {
		return _Counter;
	}

	clsPerson(string name) {
		_Name = name;
		_Counter++;
	}


	string GetName() {
		return _Name;
	}

	void SetName(string NewCount) {
		_Name = NewCount;
	}

	_declspec(property(get = GetName, put = SetName)) string Name;
};

short clsPerson::_Counter = 0;

int main() {

	clsPerson Person1("Bob");
	Printl("Username: " + Person1.Name + " Count Of Users: " + to_string(clsPerson::GetPeopleCount()) );

	clsPerson Person2("Mark");
	Printl("Username: " + Person2.Name + " Count Of Users: " + to_string(clsPerson::GetPeopleCount()) );

	clsPerson Person3("Robert");
	Printl("Username: " + Person3.Name + " Count Of Users: " + to_string(clsPerson::GetPeopleCount()) );

	return 0;
}