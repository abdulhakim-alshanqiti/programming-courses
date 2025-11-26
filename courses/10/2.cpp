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

	Person1.FirstName = "Abdulhakim"; // a different place in memory to store this data member
	Person1.LastName = "Alshanqiti";// a different place in memory to store this data member
	Printl(
		Person1.FullName() // the same place in Memory for the Member Method
	); 
	clsPerson Person2;

	Person2.FirstName = "Maher";// a different place in memory to store this data member
	Person2.LastName = "Ali";// a different place in memory to store this data member
	Printl(
		Person2.FullName()// the same place in Memory for the Member Method 
	);


	return 0;
}