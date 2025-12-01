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
	static short _Counter;
	string _Name= "";
public:

	clsPerson(string name) {
		_Name = name;
		_Counter++;
	}
	short GetCounter() {
		return _Counter;
	}

	void SetCounter(short NewCount) {
		_Counter = NewCount;
	}

	_declspec(property(get = GetCounter, put = SetCounter)) short Counter;

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

	Printl("Username: "+Person1.Name + " Count Of Users: " + to_string(Person1.Counter));

	clsPerson Person2("Mark");

	Printl("Username: "+Person2.Name + " Count Of Users: " + to_string(Person2.Counter));

	clsPerson Person3("Robert");

	Printl("Username: "+Person3.Name + " Count Of Users: " + to_string(Person3.Counter));

	return 0;
}