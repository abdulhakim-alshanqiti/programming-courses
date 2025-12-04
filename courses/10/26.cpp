#include <iostream>
#include "../../Libs/MyLib.h"
#include "../../Libs/Date.h"
#include "../../Libs/clsPerson.h"
#include "../../Libs/clsEmployee.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;



int main() {
	clsEmployee Employee(1, "Abdulhakim", "Alshanqiti", "Software Engineer", "Tech Department", 12500, "example.gmail.com", "+9660000000000");

	Employee.Print();


	return 0;

}