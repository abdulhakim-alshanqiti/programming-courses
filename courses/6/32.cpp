#include<iostream>
using namespace std;
struct stEmployee {
	string Name;
	float Salary;
};
int main() {
	stEmployee Employee1, * ptr;
	Employee1.Name = "Mohammed Abu-Hadhoud";
	Employee1.Salary = 5000;

	cout << Employee1.Name << endl;
	cout << Employee1.Salary << endl;

	ptr = &Employee1;

	cout << "\nUsing Pointer:\n";
	cout << ptr->Name << endl;
	cout << ptr->Salary << endl;

	return 0;
}