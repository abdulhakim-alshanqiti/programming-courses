#include <iostream>
#include "../../Libs/MyLib.h"
#include "../../Libs/Date.h"

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
		Printl("Address Details");
		Printl(RepeatString(30, "="));
		Printl("Address Line1: " + _Address.AddressLine1);
		Printl("Address Line2: " + _Address.AddressLine2);
		Printl("POBox: " + _Address.POBox);
		Printl("Zip Code: " + _Address.ZipCode);
	}

};
int main() {

	clsAddress Address("Square Dist", "Queen's Street", "1233", "12323");
	Address.Print();

	return 0;
}