#include <iostream>
#include "../../libs/MyLib.h"
#include "../../libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsPerson {
public:
	string FullName = "Abdulhakim Alshanqiti";


};

class clsEmployee : public clsPerson {

public:
	string Title = "CTO";

};



int main() {
	clsEmployee Employee;
	Printl("Employee Info:");

	Printl(Employee.Title);
	Printl(Employee.FullName);

	Printl("\n\n");


	clsPerson* Person = &Employee;
	Printl("Person Info:");
	Printl(Person->FullName );

	


	return 0;

}