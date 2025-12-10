#include <iostream>
#include "../../libs/MyLib.h"
using namespace std;
using namespace Output;

void AddOne() {
	static int number = 1;

	Printl(number);
	number++;
}
int main() {


	AddOne();
	AddOne();
	AddOne();
	return 0;
}