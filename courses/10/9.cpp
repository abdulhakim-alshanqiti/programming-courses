#include <iostream>
#include "../../libs/MyLib.h"
#include "../../libs/Date.h"
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsAddress {


private:

	struct _stAddress {
		string AddressLine1 = "";
		string AddressLine2 = "";
		string POBox = "";
		string ZipCode = "";
	};

	_stAddress _Address;



public:
	clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode) {
		_Address = { AddressLine1,AddressLine2,POBox,ZipCode };
	}
	// Copy Constructor
	// The copy constructor can be defined explicitly by the programmer.
	// If the programmer does not define the copy constructor, the compiler does it for us.
	//
	// if you remove the by reference passing it will throw this error
	// copy constructor for class may not have a parameter of type clsAddress
	clsAddress(clsAddress &OldObj) {
		_Address = { OldObj.AddressLine1(), OldObj.AddressLine2(), OldObj.POBox(), OldObj.ZipCode ()};
	}

	string AddressLine1() {
		return _Address.AddressLine1;
	}
	string AddressLine2() {
		return _Address.AddressLine2;
	}
	string POBox() {
		return _Address.POBox;
	}
	string ZipCode() {
		return _Address.ZipCode;
	}

	void Print() {
		Printl(RepeatString(30, "="));
		Printl("Address Details");
		Printl(RepeatString(30, "="));
		Printl("Address Line1: " + _Address.AddressLine1);
		Printl("Address Line2: " + _Address.AddressLine2);
		Printl("POBox: " + _Address.POBox);
		Printl("Zip Code: " + _Address.ZipCode);
	}

};
int main() {

	clsAddress Address1("Square Dist", "Queen's Street", "1233", "12323");
	Address1.Print();

	clsAddress Address2 = Address1;
	Address2.Print();

	return 0;
}