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
	virtual void Print() = 0;
	virtual bool HasDrivingLicense() = 0;
};

class clsEmployee : public clsPerson {
public:

	void Print() {
		Printl("Hi I am an Employee");		
	}
	bool HasDrivingLicense() {
		return true;
	}

};

class clsStudent : public clsPerson {

public:
	void Print() {
		Printl("Hi I am a Student");
	}
	bool HasDrivingLicense() {
		return false;
	}


};



int main() {
	clsEmployee Employee;
	clsStudent Student;


	Printl("Student Has A Driving License ? " + BoolToTrueAndFalse(  Student.HasDrivingLicense()  ));
	Printl("Employee Has A Driving License ? " + BoolToTrueAndFalse( Employee.HasDrivingLicense() ));


	Printl("\n\nWithout Pointers :");
	// Static/Early Binding
	Employee.Print();
	Student.Print();

	Printl("\n\nWith Pointers :");

	clsPerson * Person1 = &Employee;
	clsPerson * Person2 = &Student;

	// Dynamic/Late Binding
	Person1->Print();
	Person2->Print();


	return 0;

}