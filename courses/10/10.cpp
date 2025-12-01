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

	string _FirstName = "";
	string _LastName = "";

public:

	clsPerson() {
		Printl("Hi I am Constructor");
	}

	~clsPerson() {
		Printl("Hi I am Destructor");
	}

	void SetFirstName(string NewName) {
		_FirstName = NewName;
	}
	void SetLastName(string NewName) {
		_LastName = NewName;
	}
	string GetFirstName() {
		return _FirstName;
	}
	string LastName() {
		return _LastName;
	}


	string FullName() {
		return  _FirstName + " " + _LastName;
	};


};

void Func1() {
	clsPerson Person1;

	Person1.SetFirstName("Abdulhakim");
	Person1.SetLastName("Alshanqiti");

}

/// Creates A Vector
void Func2() {
	clsPerson* Person1 = new clsPerson;

	Person1->SetFirstName("Abdulhakim2");
	Person1->SetLastName("Alshanqiti2");
	delete Person1; // without this line the constructor won't be called
}
int main() {
	Func2();

	return 0;
}