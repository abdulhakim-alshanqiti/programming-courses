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
	string YourFullNameIs = "Your Fullname Is ";
protected:
	string separator = " ";
public:
	string FirstName = "";
	string LastName = "";

	string FullName() {
		return YourFullNameIs + FirstName + separator + LastName;
	};
};
int main() {

	clsPerson Person1;

	Person1.FirstName = "Abdulhakim"; 
	Person1.LastName = "Alshanqiti";
	Printl(Person1.FullName());


	return 0;
}