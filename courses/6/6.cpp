#include <iostream>
#include <string>
#include "../../libs/MyLib.h"
using namespace std;
using namespace Input;
using namespace Output;

int add(int a, int b);

int main() {
	cout << add(1, 2) << endl;

	return 0;
}

int add(int a, int b) {

	return a + b;
}