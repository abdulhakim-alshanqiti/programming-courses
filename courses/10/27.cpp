#include <iostream>
#include "../../Libs/MyLib.h"
#include "../../Libs/Date.h"

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;
using namespace std;

class clsEmployee {


public:
	int ID = 0;
	string Name = "";
	float Salary = 0;

	clsEmployee(int ID, string Name, float Salary) {
		this->ID = ID;
		this->Name = Name;
		this->Salary = Salary;
	}

	void Func1() {
		Func2(*this);
	}
	static void Func2(clsEmployee Employee) {
		Employee.Print();
	}
	 void Print() {
		Printl("--------------------------------------------------------------");
		Printl("ID         : " + to_string(ID));
		Printl("Salary     : " + to_string(Salary));
		Printl("Name : " + Name);
		Printl("--------------------------------------------------------------");
	}
};


int main() {
	clsEmployee Employee(1, "Abdulhakim",  12500);

	Employee.Print();
	Employee.Func1();

	return 0;

}