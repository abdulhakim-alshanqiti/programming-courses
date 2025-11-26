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
	string separator = " ";

public: 
	string FirstName = "";
	string LastName = "";

	string FullName() {
		return FirstName + separator + LastName;
	};
};
int main() {

	clsPerson Person1;


	Person1.FirstName = "Abdulhakim";
	Person1.LastName = "Alshanqiti";
	//Person1.separator; // This Will Throw an Error
	Printl(Person1.FullName());


	return 0;
}